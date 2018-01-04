//I declare upon my honor that I made this mp by myself
#include<stdio.h>
#include <string.h>
#define MAX 100
typedef struct{//struct for flags
    int fcharacter ;
    int equals ,operation,funcp,fv,fbrack,fbrackno ;
}flag;
int parse(char [40]);//parses input
int validity(char [40][MAX],int );//checks validity of the line
int convert(char [MAX],flag *,int);//converts line into current state
int main (){//main program w
    int i=0,m,size,ans;
    char arr1[40][MAX],line[40];
    FILE *fp;
    fp = fopen("mpa6.in","r");//read
    FILE *ofp;
    ofp = fopen("Pacana.out", "w");//write
    if(fp == NULL){
		printf("\nI couldn't open sample.in for reading.");
	}
    else{
        while (fgets(line, 80, fp) != NULL){//gets every line and puts it in ont array
            strcpy(arr1[i],line);
            i++;
        }
        fclose(fp);
    }
	size=i;
	for (i=0;i<size;i++){//for every item in the array it passes through a function that parses
        ans=parse(arr1[i]);
        if(ans==1){
            fprintf(ofp,"VALID\n");
        }
        else if(ans==0){
            fprintf(ofp,"INVALID\n");
        }


	}
	fclose(fp);
	    fclose(ofp);
}
int parse(char arr1[40]){
    int j,k,i,size,valid;

    char arr2[40],arr3[40][MAX];
    for(j=0,k=0,i=0;arr1[j]!='\0' && arr1[j]!='\n';j++,k++){//parses each line
        if(arr1[j]==' ' || arr1[j]==',' || arr1[j]==';' || arr1[j]=='(' || arr1[j]==')'|| arr1[j]=='[' || arr1[j]==']'){
            if(arr1[j]=='('){
                arr2[k]='\0';
                strcpy(arr3[i],arr2);
                i++;
                arr3[i][0]='(';
                arr3[i][1]='\0';
                i++;
                k=0;
                j++;
            }
                else if(arr1[j]=='['){
                arr2[k]='\0';
                strcpy(arr3[i],arr2);
                i++;
                arr3[i][0]='[';
                arr3[i][1]='\0';
                i++;
                k=0;
                j++;
            }
            else if(arr1[j]==','){
                arr2[k]='\0';
                strcpy(arr3[i],arr2);
                arr3[i+1][0]=',';
                arr3[i+1][1]='\0';
                i=i+2;
                k=0;
                j++;
                while(arr1[j]==' '){
                    j++;
                }
            }
            else{
                while(arr1[j]==' '){
                    j++;
                }
                arr2[k]='\0';
                strcpy(arr3[i],arr2);
                i++;
                k=0;
            }
        }
        arr2[k]=arr1[j];
    }
    if(arr1[j-1]==';'){//if the last line is a ;, it puts it on the end bec the above does not take into account this ';'
        arr3[i][0]=59;
        arr3[i][1]='\0';
        i++;
    }
    size=i;
    valid = validity(arr3,size);//returns whether my program deems it valid
    return valid;
}
int validity(char arr3[40][MAX],int sizearr3){
    int i,state=0,table[8][8],j;
    flag f;//initializing my flags
    f.fcharacter=0;
    f.funcp=0;
    f.equals=0;
    f.operation=0;
    f.fv=0;
    f.fbrack=0;
    f.fbrackno=0;
    for(i=0;i<8;i++){//initializing table, i noticed most of them are null so I just made all of them null and specifically the ones i need below
        for(j=0;j<8;j++){
            table[i][j]=4;
        }
    }
    table[0][0]=0;//initializing table
    table[0][1]=1;
    table[0][7]=7;
    table[0][6]=6;
    table[1][2]=2;
    table[1][3]=3;
    table[1][5]=5;
    table[1][6]=6;
    table[1][7]=7;
    table[2][1]=1;
    table[2][0]=2;
    table[5][5]=5;
    table[5][1]=1;
    table[5][3]=3;
    table[3][1]=1;
    table[6][3]=3;
    table[6][0]=0;
    table[0][2]=0;
    table[2][6]=6;

    table[7][7]=7;
    table[7][6]=6;
    table[7][1]=1;
    table[0][7]=7;

    for(i=0,state=0;i<sizearr3;i++){//finds the curren state based on the table
        state=table[state][convert(arr3[i],&f,i)];
    }
    if(state==3){
        return 1;//returns 1 if valid and 0 if not
    }
    else{
        return 0;
    }
}
int convert(char arr[MAX], flag *f,int l){//identifies my string
    int i,flag2=0;//if type:
    if(strcmp(arr,"char")==0 || strcmp(arr,"char*")==0 || strcmp(arr,"int")==0 || strcmp(arr,"int*")==0|| strcmp(arr,"float")==0 || strcmp(arr,"float*")==0|| strcmp(arr,"double")==0 || strcmp(arr,"double*")==0|| strcmp(arr,"void")==0){
        if(strcmp(arr,"void")==0){
            f->fcharacter=1;
           f->fv=1;
           return 0;
        }
        else if(f->funcp==1){
            return 0;
        }
        else if(f->fcharacter==0 || f->funcp==1){
            f->fcharacter=1;
            return 0;
        }
        else{
            return 4;
        }
    }
    else if(arr[0]=='[' || arr[0]==']'){//if brackets:
        if(arr[0]=='['){
            f->fbrack=1;
            return 7;
        }
        else if(arr[0]==']'){
            f->fbrackno=f->fbrackno+1;
            return 7;
        }
    }
    else if(arr[0]==';'){//if semi-colon
        if(f->fv==1){
            if(f->funcp==2){
                return 3;
            }
            else{
                return 4;
            }
        }
        if(f->equals==1){
            f->equals=0;
            f->operation=0;
        }
        return 3;
    }
    else if(arr[0]=='(' ||arr[0]==')'){//if parenthesis
        if(arr[0]=='('){
            f->funcp=1;
        }
        if(arr[0]==')'){
            if(f->fbrackno==1){
                return 6;
            }
            else if(f->fbrack==2){
                return 6;
            }
            else if(f->fbrack==1){
                return 4;
            }
            f->funcp=2;
        }
        return 6;
    }
    else if(arr[0]=='='){//if equals sign
        f->equals=1;
        return 5;
    }
    else if(arr[0]=='+' || arr[0]=='-'|| arr[0]=='/'|| arr[0]=='*'){//if operations
        f->operation=1;
        return 5;
    }
    else if(arr[0]==','){//if comma
        return 2;
    }
    else if(f->equals==1||f->operation==1){//if either a flag comma or flag operations is activated
         //  printf("nisud diri");
        if(arr[0]>='0' && arr[9]<='9'){
            for(i=0;arr[i]!='\0';i++){
                if(arr[i]>='0' && arr[i]<='9'){
                    return 1;
                }
            }
        }
        else if(!(arr[0]>='A' && arr[0]<='Z' ||arr[0]>='a' && arr[0]<='z'|| arr[0]==39 )){
            return 4;
        }
        else{
            for(i=0;arr[i]!='\0';i++){
                if(!(arr[i]>='A' && arr[i]<='Z' ||arr[i]>='a' && arr[i]<='z' || arr[i]>='0' && arr[i]<='9' ||arr[i]>='_')){
                    flag2=1;
                }
                if(arr[i]==39 && flag2==0){
                    flag2=1;
                }
                else if(arr[i]==39 && flag2==1){
                    flag2=0;
                }
            }
            if(flag2==0){
                return 1;
            }
            else{
                return 4;
            }
        }
    }
    else if(arr[0]>='A' && arr[0]<='Z' ||arr[0]>='a' && arr[0]<='z'){//if character
        flag2=0;//IF PREDEFINED FUNCTION
        if(f->fcharacter!=1 || strcmp(arr,"while")==0 ||strcmp(arr,"printf")==0||strcmp(arr,"scanf")==0||strcmp(arr,"for")==0||strcmp(arr,"else")==0||strcmp(arr,"if")==0||strcmp(arr,"struct")==0||strcmp(arr,"typedef")==0||strcmp(arr,"kar")==0){
            return 4;
        }
        for(i=1;arr[i]!='\0';i++){
            if (arr[i]>='A' && arr[i]<='Z' ||arr[i]>='a' && arr[i]<='z' || arr[i]>='0' && arr[i]<='9' ||arr[i]>='_'){
                if(f->fbrack==1){
                    f->fbrack=2;
                }
            }
            else{
                flag2=1;
            }
        }
        if(flag2==0){
            return 1;
        }
        else{
            return 4;
        }
    }
    else if(arr[0]>='0' && arr[0]<='9'){//if number
        for(i=0;arr[i]!='\0';i++);
        if(arr[i]!='\0'){
            return 4;
        }
        else{
            f->fbrack=2;
            return 1;
        }
    }
    else{//if none of the above
        return 4;
    }
}
