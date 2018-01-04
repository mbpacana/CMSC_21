//I declare upon my honor that I made this mp by myself
//eternal loop     while(fgets(buff, BUFSIZE-1, ifp) != NULL)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
typedef struct elem{//initializing structs
    char stdnum[50],ftname[50],ltname[50],mdname[50],prog[50];
    int year;
    struct elem *next;
}info;
typedef struct{
    info *head, *tail;
    int size;
}list;
void init(list*);
void withdraw(list *isko,char*);
void searchyear(list*,int);
void searchsnum(list*, char[100]);
void searchfam(list*,char[100]);
void searchcourse(list*,char[100]);
void enroll(list*,info);
int main(){//main function
    int balik,i,choice,syear,j,flag=0,k;
    char stnum[100];
    list isko;
    init(&isko);
    FILE *fp,*op;
    info *temp=isko.head,iskolar;
    op=fopen("mpa9.out","r");//my database
    if(op == NULL);
	else{
        fscanf(op," %i",&balik);
        for(i=0;i<balik;i++){
            fscanf(op," %s", iskolar.stdnum);
            fscanf(op," %s", iskolar.ltname);
            fscanf(op," %[^\n]s", iskolar.ftname);
            fscanf(op," %s", iskolar.mdname);
            fscanf(op," %[^\n]s", iskolar.prog);
            fscanf(op," %i", &iskolar.year);
            enroll(&isko,iskolar);
        }
	}
    fp=fopen("mpa9.in","r");//the input file
    if(fp == NULL){
		printf("\nI couldn't open mpa9.in for reading.");
	}
	else{
        fscanf(fp,"%i",&balik);
        for(i=0;i<balik;i++){
            fscanf(fp,"%i",&choice);
            if (choice==1){
                fscanf(fp," %s", stnum);
                temp=isko.head;
                for (j=0,flag=0,temp=isko.head;j<isko.size;j++){
                    if(strcmp(temp->stdnum,stnum)==0){
                    flag=1;
                    }
                    temp=temp->next;
                }
                if(flag==1){
                    printf("THE STUDENT NUMBER %s ALREADY EXISTS.\n\n",stnum);
                }
                strcpy(iskolar.stdnum,stnum);
                fscanf(fp," %[^\n]s", iskolar.ftname);
                fscanf(fp," %s", iskolar.mdname);
                fscanf(fp," %s", iskolar.ltname);
                fscanf(fp," %[^\n]s", iskolar.prog);
                fscanf(fp," %i", &iskolar.year);

                if(flag==0){
                    enroll(&isko,iskolar);
                }
                display(isko);
            }
            if (choice==2){//withdraws
                fscanf(fp," %s", stnum);
                withdraw(&isko,stnum);
            }
            if (choice==3){//displays
                display(isko);
            }
            if (choice==4){//searches same year
               fscanf(fp," %i", &syear);
        [50]        searchyear(&isko, syear);

            }
            if (choice==5){//searches same course
                fscanf(fp," %[^\n]s", stnum);
                searchcourse(&isko,stnum);
            }
            if (choice==6){//searches same fam name
                fscanf(fp," %s", stnum);
                searchfam(&isko,stnum);
            }
            if (choice==7){//searches stdnum
                fscanf(fp," %s", stnum);
                searchsnum(&isko,stnum);
            }
        }
	}
	op=fopen("mpa9.out","w");
	temp=isko.head;
	fprintf(op,"%i\n", isko.size);
    for(i=0;i<isko.size;i++){
        fprintf(op,"%s\n", temp->stdnum);
        fprintf(op,"%s\n%s\n%s\n",temp->ltname,temp->ftname,temp->mdname);
        fprintf(op,"%s\n",temp->prog );
        fprintf(op,"%i\n",temp->year);
        temp=temp->next;
    }
    return 0;
}
void enroll(list *isko,info iskolar){//enrolls
    info *n=malloc(sizeof(info));
    strcpy(n->stdnum,iskolar.stdnum);
    strcpy(n->ftname,iskolar.ftname);
    strcpy(n->mdname,iskolar.mdname);
    strcpy(n->ltname,iskolar.ltname);
    strcpy(n->prog,iskolar.prog);
    n->year=iskolar.year;
    if(isko->size==MAX){
        return 0;
    }
    else{
        if(isko->size==0){
            isko->head = isko->tail = n;
        }
        else{
            isko->tail->next=n;
            isko->tail=n;
        }
        isko->size++;
    }
}
void searchcourse(list *isko,char course[100]){//searches info of students of the same course
    int i,flag=0;
    info *temp=isko->head,*del;
    if(strcmp(temp->prog,course)==0){
        flag=1;
        printf("Student Number: %s\n", temp->stdnum);
        printf("Name: %s, %s %s\n",temp->ltname,temp->ftname,temp->mdname);
        printf("Program: %s\n",temp->prog );
        printf("Year Level: %i\n\n",temp->year);
        //printf("%s\n%s\n%i",course,temp->prog,isko->size-1);
    }
    for(i=0;i<isko->size-1;i++){

        if(strcmp(temp->next->prog,course)==0){
            flag=1;
            printf("Student Number: %s\n", temp->next->stdnum);
            printf("Name: %s, %s %s\n",temp->next->ltname,temp->next->ftname,temp->next->mdname);
            printf("Program: %s\n",temp->next->prog );
            printf("Year Level: %i\n\n",temp->next->year);
        }
        temp=temp->next;
    }
    if(flag==0){
        printf("NO STUDENT WITH THE COURSE %s EXISTS.\n",course);
    }
}
void searchfam(list *isko,char fam[100]){//searches info of students of the same fam name
    int i,flag=0;
    info *temp=isko->head,*del;
    if(strcmp(temp->ltname,fam)==0){
        flag=1;
        printf("Student Number: %s\n", temp->stdnum);
        printf("Name: %s, %s %s\n",temp->ltname,temp->ftname,temp->mdname);
        printf("Program: %s\n",temp->prog );
        printf("Year Level: %i\n\n",temp->year);
    }
    for(i=0;i<isko->size-1;i++){
        if(strcmp(temp->next->ltname,fam)==0){
            flag=1;
            printf("Student Number: %s\n", temp->next->stdnum);
            printf("Name: %s, %s %s\n",temp->next->ltname,temp->next->ftname,temp->next->mdname);
            printf("Program: %s\n",temp->next->prog );
            printf("Year Level: %i\n\n",temp->next->year);
        }
        temp=temp->next;
    }
    if(flag==0){
        printf("NO STUDENT WITH THE FAMILY NAME %s EXISTS.\n",fam);
    }
}
void searchsnum(list *isko,char num[100]){//searches info of students of the same stud number
    int i,flag=0;
    info *temp=isko->head,*del;
    if(strcmp(temp->stdnum,num)==0){
        flag=1;
        printf("Student Number: %s\n", temp->stdnum);
        printf("Name: %s, %s %s\n",temp->ltname,temp->ftname,temp->mdname);
        printf("Program: %s\n",temp->prog );
        printf("Year Level: %i\n",temp->year);
            printf("\n");
    }
    for(i=0;i<isko->size-1;i++){
        if(strcmp(temp->next->stdnum,num)==0){
            flag=1;
            printf("Student Number: %s\n", temp->next->stdnum);
            printf("Name: %s, %s %s\n",temp->next->ltname,temp->next->ftname,temp->next->mdname);
            printf("Program: %s\n",temp->next->prog );
            printf("Year Level: %i",temp->next->year);
            printf("\n");
        }
        temp=temp->next;
    }
    if(flag==0){
        printf("NO STUDENT WITH THE COURSE %s EXISTS.\n",num);
    }
}
void searchyear(list*isko,int year){// searches infos of students of the same year
    int i,flag=0;
    info *temp=isko->head,*del;
    if(temp->year==year){
        flag=1;
        printf("Student Number: %s\n", temp->stdnum);
        printf("Name: %s, %s %s\n",temp->ltname,temp->ftname,temp->mdname);
        printf("Program: %s\n",temp->prog );
        printf("Year Level: %i\n\n",temp->year);
    }
    for(i=0;i<isko->size-1;i++){
        if(temp->next->year==year){
            flag=1;
            printf("Student Number: %s\n", temp->next->stdnum);
            printf("Name: %s, %s %s\n",temp->next->ltname,temp->next->ftname,temp->next->mdname);
            printf("Program: %s\n",temp->next->prog );
            printf("Year Level: %i\n\n",temp->next->year);
        }
        temp=temp->next;
    }
    if (flag==0){
        printf("NO STUDENT WITH YEAR LEVEL %i EXISTS.\n",year);
    }
}

void init(list *l){//initializes a list
    l->size = 0;
    l->head = l->tail = NULL;
}
void display(list isko){//displays the students
    int i=0;
    info *temp=isko.head;
    for(i=0;i<isko.size;i++){
        printf("Student Number: %s\n", temp->stdnum);
        printf("Name: %s, %s %s\n",temp->ltname,temp->ftname,temp->mdname);
        printf("Program: %s\n",temp->prog );
        printf("Year Level: %i\n",temp->year);
        printf("\n");
        temp=temp->next;
    }
}
void withdraw(list *isko,char stnum[100]){//withdraw sa student from enrollment
    int i,flag=0;
    info *temp=isko->head,*del;
    if(strcmp(temp->stdnum,stnum)==0){
        del=isko->head;
        isko->head=del->next;
        del->next=NULL;
        free(del);
		isko->size--;
    }
    for(i=0;i<isko->size-1;i++){
        if(strcmp(temp->next->stdnum,stnum)==0){
                del = temp->next;
                temp->next = del->next;
                del->next = NULL;
                if(del==isko->tail)
                    isko->tail = temp;
                free(del);
                isko->size--;
                break;
        }
        else{
            temp=temp->next;
        }
    }
    display(*isko);
}

