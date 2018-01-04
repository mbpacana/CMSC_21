//I declare upon my honor that I made this mp by myself
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
typedef struct elem{//I've put them inside the struct
    char word[100];
    int comparebin,comparelist;
    struct elem *next;
}data;

typedef struct holder{
    data lword;
    int count;
    struct holder *left;
    struct holder *right;
}btnode;

typedef struct{
    data *head,*tail;
    int size;
}list;

int display1(btnode *,char *);
int display2(list,char *);
btnode *addItem(btnode *,data);
void append(list*,char*);
void init(list*);
int main (){//my main
    btnode *root =NULL;
    data w;
    list l;
    init(&l);
    w.comparebin=1;
    char x[100], find[20];
    int n,i,ans=0;
    FILE *fp;
    FILE *op;
    fp=fopen("words.data","r");
    op=fopen("mpa8.in","r");
    if(fp == NULL){
		printf("\nI couldn't open sample.in for reading.");
	}
	else{
        for(;fscanf(fp,"%s",x)!=EOF;){
            strcpy(w.word,x);
            root=addItem(root,w);
            append(&l,x);
        }
        fscanf(op,"%i",&n);
        for(i=0;i<n;i++){
            fscanf(op,"%s",find);
            ans=display1(root,find);
            printf("%s: %i",find,ans);
            ans=display2(l,find);
            printf(" %i\n",ans);
        }
	}
    return 0;
}
int display2(list l,char *find){//search for linked list
    data *temp;
    temp=l.head;
    for(;temp->next!=NULL;temp=temp->next){
        if(strcmp(temp->word,find)==0){
            return temp->comparelist;
        }
    }
    return l.size;
}
void init(list* l){//initializes list
    l->head=l->tail=NULL;
    l->size=0;
}
void append(list* l,char *w){//appends a list
    data *node=malloc(sizeof(data)),*temp;

    strcpy(node->word,w);
    node->comparebin=NULL;
    node->next=NULL;

    if(l->head==NULL){
        node->comparelist=1;
        l->head=l->tail=node;
    }
    else{
        node->comparelist=l->size+1;
        l->tail->next=node;
        temp->next=node;
        l->tail=node;
    }
    l->size++;
}
int display1(btnode *r,char *find){//my main search that recursively return the count of binary tree
    //printf("\n%s",find);
    if(r!=NULL){
        if(strcmp(r->lword.word,find)==0){
            return 1;
        }
        else if(strcmp(r->lword.word,find)>0){
            return 1+display1(r->left,find);
        }
        else{
            return 1+display1(r->right,find);
        }
    }
    return 0;
}
btnode *addItem(btnode *r,data w){
    if(r==NULL){
        r=malloc(sizeof(btnode));
        strcpy(r->lword.word,w.word);
        r->lword.comparebin=w.comparebin;
        r->count=1;
        r->left=NULL;
        r->right=NULL;
    return r;
    }
else{
        if(strcmp(r->lword.word,w.word)==0){
            r->count++;
            return r;
        }
        else{
            if(strcmp(r->lword.word,w.word)<0){
               // printf("\nright %s and %s with %i",r->lword.word,w.word,w.comparebin);
                w.comparebin+=1;
                r->right=addItem(r->right,w);
                return r;
            }
            else{
               // printf("\nleft %s and %s with %i",r->lword.word,w.word,w.comparebin);
                w.comparebin+=1;
                r->left=addItem(r->left,w);
                return r;
            }
        }
    }
}

