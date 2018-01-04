#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int main() {
    int r,i,op;
    int ten,n,j,S1[10],temp,a,rm,flag,SR3[7]={1,5,10,50,100,500,1000},S[100],k,ans;//first operation variables
    char S2[4][10]={"HUNDRED","THOUSAND","MILLION","BILLION"},S4[10][8]={"","","TWENTY","THIRTY","FORTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY"},S3[10][6]={"","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"},S5[10][10]={"TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};
    char SR1[11],limit;
    printf("\nPlease input how many times you would like this to iterate.");
    scanf("%i",&r);
    for(k=0;k<r;k++){
        printf("\nPlease select what you would like to do:\n\t 1. Numbers to words \n\t 2. Integer to Roman Numerals \n\t 3. Roman Numeral to Integer\n\t");
        scanf("%i",&op);
        if(op==1){//numbers to words
            flag=0;//initialization
            scanf("%i",&n);
            if(n>2147483647 || n<-2147483647){
                printf("INVALID");
            }
            else{
                if(n==0){
                    printf("ZERO");
                }
                else{
                   if(n<0){
                        n=n*(-1);
                        printf("NEGATIVE ");
                    }
                    for(j=0,ten=10;n>0;j++){
                        S1[j]=n%ten;
                        n=(n-S1[j])/10;
                       // printf("%i. %i %i\n",S1[j],n,j);
                    }
                    for(j--,temp=j;j+1>0;j--){
                        //printf("\nThe j %i %i",j, S1[j]);
                        if(j!=temp && (j+1)%3==0){
                            rm=(j+1)/3;
                           if(rm!=0){
                                printf("%s ",S2[rm]);
                            }
                        }
                        if((j+1)%3==0){
                            if(S1[j]!=0){
                                printf("%s ",S3[S1[j]]);
                                printf("%s ",S2[0]);
                            }
                        }
                        else if((j+2)%3==0 ){
                            if(S1[j]==1){
                                flag=1;
                            }
                            else{
                                if(S1[j]!=0){
                                    printf("%s",S4[S1[j]]);
                                }
                                if(S1[j]!=0 && S1[j-1]!=0){
                                    printf("-");
                                }
                            }
                        }
                        else if((j+3)%3==0){
                            if(flag==1){
                                flag==0;
                                    printf("%s ",S5[S1[j]]);
                            }
                            else{
                                if((j-1)!=0){
                                    if(S1[j]!=0){
                                        printf("%s ",S3[S1[j]]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else if(op==2){//integer to Roman numeral
            scanf("%i",&n);
            if(n>3000 || n<1){
                printf("INVALID");
            }
            else{
                while(SR3[6]<=n){
                    n=n-SR3[6];
                    printf("M");
                }
                if(SR3[4]<=n){
                    ans=0;
                    ans=n/SR3[4];
                   if(ans==9){
                        n-=(9*SR3[4]);
                        printf("CM");
                    }
                    else {
                        if(ans==4){
                            n-=(4*SR3[4]);
                            printf("CD");
                        }
                        else{
                            if(ans>=5){
                                n-=SR3[5];
                                ans-=5;
                                printf("D");
                            }
                            for(i=0;ans!=0;ans--){
                                n-=SR3[4];
                                printf("C");
                            }
                        }
                    }
                }
                if(SR3[2]<=n){
                    ans=0;
                    ans=n/SR3[2];
                   if(ans==9){
                        n-=(9*SR3[2]);
                        printf("XC");
                    }
                    else {
                        if(ans==4){
                            n-=(4*SR3[2]);
                            printf("XL");
                        }
                        else{
                            if(ans>=5){
                                n-=SR3[3];
                                ans-=5;
                                printf("L");
                            }
                            for(i=0;ans!=0;ans--){
                                n-=SR3[2];
                                printf("X");
                            }
                        }
                    }
                }
                if(SR3[0]<=n){
                    ans=0;
                    ans=n/SR3[0];
                   if(ans==9){
                        n-=(9*SR3[0]);
                        printf("IX");
                    }
                    else {
                        if(ans==4){
                            n-=(4*SR3[0]);
                            printf("IV");
                        }
                        else{
                            if(ans>=5){
                                n-=SR3[1];
                                ans-=5;
                                printf("V");
                            }
                            for(i=0;ans!=0;ans--){
                                n-=SR3[0];
                                printf("I");
                            }
                        }
                    }
                }
            }
        }
        else if(op==3){//Roman numeral to Integer
            flag=6;
            scanf("%s",SR1);
            //printf("\n%s",SR1);
            for(i=0,ans=0;SR1[i]!='\0';i++){
                //printf("\n%c %i",SR1[i],i);
                if(SR1[i]=='I'){
                    SR1[i]='0';
                }
                else if(SR1[i]=='V'){
                    SR1[i]='1';
                }
                else if(SR1[i]=='X'){
                    SR1[i]='2';
                }
                else if(SR1[i]=='L'){
                    SR1[i]='3';
                }
                else if(SR1[i]=='C'){
                    SR1[i]='4';
                }
                else if(SR1[i]=='D'){
                    SR1[i]='5';
                }
                else if(SR1[i]=='M'){
                    SR1[i]='6';
                }
            }
            limit=i-1;
            for(i=0,ans=0,flag=0;SR1[i]!='\0';i++){
                //printf("\n%i",ans);
                if(i<limit){
                    if(SR1[i]<SR1[i+2]){
                        flag=-1;
                        break;
                    }
                }
                    if(SR1[i]=='0'){
                       if(SR1[i+1]=='2' && SR1[i+1]!='\0'){
                            ans=ans+(SR3[0]*9);
                            i++;
                        }
                        else if(SR1[i+1]=='1' && SR1[i+1]!='\0'){
                            ans=ans+(SR3[0]*4);
                            i++;
                        }
                        else if(SR1[i+1]>'2'){
                           flag=-1;
                           break;
                        }
                        else{
                            ans=ans+SR3[0];
                        }
                    }
                    else if(SR1[i]=='1'){
                        if(SR1[i+1]>='1'){
                           flag=-1;
                           break;
                        }
                        else{
                            ans=ans+SR3[1];
                        }
                    }
                    else if(SR1[i]=='2'){
                       if(SR1[i+1]=='4' && SR1[i+1]!='\0'){
                            ans=ans+(SR3[2]*9);
                            i++;
                        }
                        else if(SR1[i+1]>='5'){
                           flag=-1;
                           break;
                        }
                        else{
                            ans=ans+SR3[2];
                        }
                    }
                    else if(SR1[i]=='3'){
                        if(SR1[i+1]>='3' ){
                            flag=-1;
                            break;
                        }
                        else{
                            ans=ans+SR3[3];
                        }
                    }
                    else if(SR1[i]=='4'){
                        if(SR1[i+1]=='6' && SR1[i+1]!='\0'){
                            ans=ans+(SR3[4]*9);
                            i++;
                        }
                        else if(SR1[i+1]=='5' && SR1[i+1]!='\0'){
                            ans=ans+(SR3[4]*4);
                            i++;
                        }
                        else if(SR1[i+1]>='5'){
                           flag=-1;
                           break;
                        }
                        else{
                            ans=ans+SR3[4];
                        }
                    }
                    else if(SR1[i]=='5'){
                        if(SR1[i+1]>='5'){
                           flag=-1;
                           break;
                        }
                        else{
                            ans=ans+SR3[5];
                        }
                    }
                    else if(SR1[i]=='6' ){
                        ans=ans+SR3[6];
                    }
            }
            if(flag==-1){
                    flag=-1;
                    printf("INVALID");
            }
            else{
                printf("%i",ans);
            }
        }
        else{
            printf("INVALID");
        }
    printf("\n");
    }
    return 0;
}

