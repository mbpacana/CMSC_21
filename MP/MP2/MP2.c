//I declare upon my honor that I made this mp by myself
#include <stdio.h>
void display(char table[3][3]);
int main(){
    system("color 0B");
    unsigned int i,j,m,a,b,repeat,score1=0,score2=0;
    int flag=0;
    char ta[3][3]={{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'}};
    printf("\n Welcome to Tic-Tac-Toe. \n\t Instructions: Enter the coordinates of your choice with the first number being the x-axis coordinate and second number being the y-axis. Seperate coordinates with a space.");
    for(repeat=1;repeat==1;){
        for(m=0;m<9;m++,flag=1){
            if(m%2==0){
                do{
                    flag=1;
                    printf("\n Player 1, Please enter the coordinates.");
                    scanf("%u %u", &i,&j);
                    if(i>3 || j>3){
                        printf("\n Coordinates Invalid ");
                        flag=0;
                    }
                    else{
                        if(ta[i-1][j-1]!='\0'){
                            printf("\n Cell already filled");
                            flag=0;
                        }
                        else
                            ta[i-1][j-1]='X';
                    }
                }while(flag==0);
            }
            else if(m%2==1){
                do{
                    flag=1;
                    printf("\nPlayer 2, Please enter the coordinates.");
                    scanf("%u %u", &i,&j);
                    if(i>3 || j>3){
                        flag=0;
                    }
                    else{
                        if(ta[i-1][j-1]!='\0'){
                            printf("\n Cell already filled");
                            flag=0;
                        }
                        else
                            ta[i-1][j-1]='O';
                    }
                }while(flag==0);
            }
            display(ta);
            if(ta[0][0]=='X' && ta[0][1]=='X' && ta[0][2]=='X' || ta[1][0]=='X' && ta[1][1]=='X' && ta[1][2]=='X' || ta[2][0]=='X' && ta[2][1]=='X' && ta[2][2]=='X' || ta[0][1]=='X' && ta[1][1]=='X' && ta[2][1]=='X' || ta[0][0]=='X' && ta[1][0]=='X' && ta[2][0]=='X' || ta[0][2]=='X' && ta[1][2]=='X' && ta[2][2]=='X' || ta[0][0]=='X' && ta[1][1]=='X' && ta[2][2]=='X' ||ta[0][2]=='X' && ta[1][1]=='X' && ta[2][0]=='X'){
                printf("Player 1 is the winner");
                score1++;
                break;
            }
            else if(ta[0][0]=='O' && ta[0][1]=='O' && ta[0][2]=='O' || ta[1][0]=='O' && ta[1][1]=='O' && ta[1][2]=='O' || ta[2][0]=='O' && ta[2][1]=='O' && ta[2][2]=='O' || ta[0][1]=='O' && ta[1][1]=='O' && ta[2][1]=='O' || ta[0][0]=='O' && ta[1][0]=='O' && ta[2][0]=='O' || ta[0][2]=='O' && ta[1][2]=='O' && ta[2][2]=='O' || ta[0][0]=='O' && ta[1][1]=='O' && ta[2][2]=='O' ||ta[0][2]=='O' && ta[1][1]=='O' && ta[2][0]=='O'){
                printf("Player 2 is the winner");
                score2++;
                break;
            }
            else if (m==8){
                printf(" It is a tie");
            }
        }
        do{
            printf("\nCurrent wins:\n\tPlayer 1: %i\n\tPlayer 2: %i \nDo you want to continue?Please choose the number of your choice \n\t1.Yes\n\t2.No\n",score1,score2);
            scanf(" %i", &repeat);
        }while(repeat>2 || repeat<1);
        if (repeat==1){
            for(i=0,j=0;i<3;j++){
                ta[i][j]='\0';
                display(ta);
                if(j==2){
                    i++;
                    j=-1;
                }
            }
        }
        else{
            return 0;
        }
    }
}
void display(char table[3][3]){
    //201 203 187 188 185 204 205 206 186
    system("cls");
    printf("\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,203,205,205,205,203,205,205,205,187);
    printf("%c %c %c %c %c %c %c\n",186,table[0][0],186,table[0][1],186,table[0][2],186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("%c %c %c %c %c %c %c\n",186,table[1][0],186,table[1][1],186,table[1][2],186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("%c %c %c %c %c %c %c\n",186,table[2][0],186,table[2][1],186,table[2][2],186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,202,205,205,205,202,205,205,205,188);
}
