//I declare upon my honor that I made this mp by myself.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct elem{//initializing structs
    int cons,exp; //data
    struct elem *next;
}node;
typedef struct{
    node *head, *tail;
    int size;
}list;
void parse(list *,char *);
void append(list*,int,int);
void init(list*);
void display(list);
void add(list *l, list *l2);
void arrange(list);
int expAt(list,int);
int consAt(list,int);
int setItem(list*,int,int);
int setExp(list*,int,int);
void sub(list l, list l2);
void mult(list l, list l2);
int main() {//main function
    char eqn1[100],eqn2[100];
    int n,i;
    list e1,e2;
    FILE *fp;
    fp=fopen("mpa7.in","r");
    if(fp == NULL){
		printf("\nI couldn't open sample.in for reading.");
	}
    fscanf(fp,"%i",&n);
    for(i=1;i<=n;i++){//input
        init(&e1);
        init(&e2);
        fscanf(fp,"%s",eqn1);
        fscanf(fp,"%s",eqn2);
        parse(&e1,eqn1);
        parse(&e2,eqn2);
        add(&e1,&e2);
        sub(e1,e2);
        mult(e1,e2);
    }
    return 0;
}
void mult(list l, list l2){//multiplying
    list sum,temp;
    init(&sum);
    init(&temp);
    int c=1,d,i,j,valid;
    for(c=1;c<=l.size;c++){//combining the first and second string
        for(d=1;d<=l2.size;d++){
            append(&sum,consAt(l,c)*consAt(l2,d),expAt(l,c)+expAt(l2,d));
        }
    }
    for(i=1;i<sum.size;i++){//simplifying them
        for(j=i+1;j<=sum.size;j++){
            if(expAt(sum,i)==expAt(sum,j)){
                valid=setItem(&sum,i,consAt(sum,i)+consAt(sum,j));
                valid=deleteItem(&sum,j);
                j--;
            }
        }
    }
    for(i=1,c=0;i<sum.size;i++){//arranging them
        for(j=i+1;j<=sum.size;j++){
            if(expAt(sum,i)<expAt(sum,j)){
                append(&temp, consAt(sum,j),expAt(sum,j));
                c++;
                valid=setItem(&sum,j,consAt(sum,i));
                valid=setExp(&sum,j,expAt(sum,i));
                valid=setItem(&sum,i,consAt(temp,c));
                valid=setExp(&sum,i,expAt(temp,c));
            }
        }
    }
    display(sum);
}
void sub(list l, list l2){
    list sum,temp;
    init(&sum);
    init(&temp);
    int c=1,i,j,valid;
    for(c=1;c<=l.size;c++){//combining the first and second string
        append(&sum,consAt(l,c),expAt(l,c));
    }
    for(c=1;c<=l2.size;c++){
        append(&sum,-1*consAt(l2,c),expAt(l2,c));
    }
    for(i=1;i<sum.size;i++){//simplifying them
        for(j=i+1;j<=sum.size;j++){
            if(expAt(sum,i)==expAt(sum,j)){
                valid=setItem(&sum,i,consAt(sum,i)+consAt(sum,j));
                valid=deleteItem(&sum,j);
                j--;
            }
        }
    }
    for(i=1,c=0;i<sum.size;i++){//arranging them
        for(j=i+1;j<=sum.size;j++){
            if(expAt(sum,i)<expAt(sum,j)){
                append(&temp, consAt(sum,j),expAt(sum,j));
                c++;
                valid=setItem(&sum,j,consAt(sum,i));
                valid=setExp(&sum,j,expAt(sum,i));
                valid=setItem(&sum,i,consAt(temp,c));
                valid=setExp(&sum,i,expAt(temp,c));
            }
        }
    }
    display(sum);
}
void display(list l){//displaying them
    node *tmp = l.head;
    while(tmp!=NULL){
        if(tmp->exp!=0 && tmp->exp!=1){
            if(tmp->cons==1 || tmp->cons==-1){
                printf("x^%d", tmp->exp);
            }
            else if(tmp->cons==0);
            else{
                printf("%dx^%d",tmp->cons,tmp->exp);
            }
        }
        else if(tmp->exp==1){
            printf("%dx", tmp->cons);
        }
        else{
            printf("%d",tmp->cons);
        }
        if(tmp->next!=NULL){
            if(tmp->next->cons > 0){
                printf("+");
            }
            else if(tmp->next->cons ==-1){
                printf("-");
            }
        }
            tmp = tmp->next;
    }
        printf("\n");
}
void parse(list *e1,char *eqn1){//parsing them
   char *token,operations,opn[20],parsedterms[100][100],temp[100];
   int i,j,k,plus,size;
   list *l=malloc(sizeof(list));
   init(l);
    if(eqn1[0]!='-'){
            opn[0]='+';
    }
    else{
            opn[0]='-';
    }
   for(i=1,k=1;eqn1[i]!='\0';i++){
        if(eqn1[i]=='+'){
            opn[k]='+';
            k++;
        }
        else if(eqn1[i]=='-'){
            opn[k]='-';
            k++;
        }
   }
   size=k;
   token=strtok(eqn1,"+-");
   k=0;
    while( token != NULL ){
        strcpy(parsedterms[k++],token);
        //
        token=strtok(NULL, "+-");
   }
   int fcoef,fvar,fexp,coef=0,exp=0;
   for(i=0,fcoef=0,fvar=0,fexp=0;i<size;i++,fcoef=0,fvar=0,fexp=0){
        for(j=0,k=0;parsedterms[i][j]!='\0';j++,k++){
            if(parsedterms[i][j]>='0' && parsedterms[i][j]<='9' && fexp==0 ){
                fcoef=1;
            }
            if(parsedterms[i][j]=='x'){
                temp[k]='\0';
                if(fcoef==1)
                    coef=atoi(temp);
                else
                    coef=1;
                if(opn[i]=='-')
                    coef=-1*coef;

                fvar=1;
                k=0;
                j++;
            }
            if(parsedterms[i][j]=='^'){
                fexp=1;
                j++;
            }
            temp[k]=parsedterms[i][j];
        }
        temp[k]='\0';
        if(fexp==1){
                exp=atoi(temp);
        }
        else{
            if(fvar==1){
                exp=1;
            }
            else if(fvar==0){
                coef=atoi(temp);
                exp=0;
                if(opn[i]=='-'){
                        coef=-1*coef;
                }
            }
        }
        //printf("\n%i %i",coef,exp);
        append(e1,coef,exp);
   }
   return e1;
}
void append(list* l,int x,int y){//adds a term at the end off the list
    node *n = malloc(sizeof(node));
    n->cons = x;
    n->exp = y;
    n->next = NULL;
    if(l->size==0){
        l->head = l->tail = n;
    }
    else{
        l->tail->next = n;
        l->tail = n;
    }
    l->size++;
}
void init(list* l){
    l->size = 0;
    l->head = l->tail = NULL;
}
void add(list *l, list *l2){//add
    list sum,temp;
    init(&sum);
    init(&temp);
    int c=1,i,j,valid;
    for(c=1;c<=l->size;c++){//putting them into 1 string
        append(&sum,consAt(*l,c),expAt(*l,c));
    }
    for(c=1;c<=l2->size;c++){
        append(&sum,consAt(*l2,c),expAt(*l2,c));
    }
    for(i=1;i<sum.size;i++){//simplifying
        for(j=i+1;j<=sum.size;j++){
            if(expAt(sum,i)==expAt(sum,j)){
                valid=setItem(&sum,i,consAt(sum,i)+consAt(sum,j));
                valid=deleteItem(&sum,j);
                j--;
            }
        }
    }
    for(i=1,c=0;i<sum.size;i++){//arranging
        for(j=i+1;j<=sum.size;j++){
            if(expAt(sum,i)<expAt(sum,j)){
                append(&temp, consAt(sum,j),expAt(sum,j));
                c++;
                valid=setItem(&sum,j,consAt(sum,i));
                valid=setExp(&sum,j,expAt(sum,i));
                valid=setItem(&sum,i,consAt(temp,c));
                valid=setExp(&sum,i,expAt(temp,c));
            }
        }
    }
    display(sum);
}
int setExp(list *l, int pos, int x){//setting exponent to a value
    if(pos<1 || pos > l->size)
        return 0;
    node *tmp = l->head;
    int i = 1;
    while(i<pos){
        tmp = tmp->next;
        i++;
    }
    tmp->exp = x;
    return 1;
}

int deleteItem(list* l,int pos){//deleting an entire node
    node *tmp = l->head, *del;
    int i = 1;
    if(pos<1 || pos>l->size)
        return 0;
    else{
        if(pos==1){
            del = l->head;
            l->head = del->next;
            del->next = NULL;
        }
        else{
            while(i<pos-1){
                tmp = tmp->next;
                i++;
            }
            del = tmp->next;
            tmp->next = del->next;
            del->next = NULL;
            if(del==l->tail)
            l->tail = tmp;
        }
        free(del);
        l->size--;
    }
    return 1;
}
int setItem(list *l, int pos, int x){//setting an item to a value
    if(pos<1 || pos > l->size)
        return 0;
    node *tmp = l->head;
    int i = 1;
    while(i<pos){
        tmp = tmp->next;
        i++;
    }
    tmp->cons = x;
    return 1;
}
int expAt(list l, int pos){//return the constant at a given pos
    node *tmp = l.head;
    int i = 1;
    while(i<pos){
        tmp = tmp->next;
        i++;
    }
    return tmp->exp;
}
int consAt(list l, int pos){//return the constant at a given pos
    node *tmp = l.head;
    int i = 1;
    while(i<pos){
        tmp = tmp->next;
        i++;
    }
    return tmp->cons;
}
