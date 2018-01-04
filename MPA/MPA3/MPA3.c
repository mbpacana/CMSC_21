//I declare upon my honor that I made this mp by myself
#include <stdio.h>//libraries
#include<time.h>
void display(char table[10][10]);//function to display
int main(){
    srand((unsigned int)time(NULL));//time
    char ta[10][10],item[3][4]={{'M','I','K','E'},{9,9,9,9},{0,0,0,0}};//variables
    int i=9,j=0,pnum,move,a,adif,phold,finish=0,snakes[3][4],ladders[3][4],ctr,z,y,w,x,flag=0,ctr2,b,c,d,e,ctrstore1,ctrstore;
    for(i=0;i<10;i++)//nulls
        for(j=0;j<10;j++)
            ta[i][j]='\0';
    do{
        printf("\n Welcome to snake and ladders with a twist. Here comes the twist. The snakes and the ladders randomly CHANGE locations for every turn. \n Please enter the number of players that will be playing.");
        scanf(" %i", &pnum);
    }while(pnum>4 ||pnum<1);//instructions
    printf("\n\tLegend:\n\t^ head of snake\n\tv tail of snake\n\tH top of ladder\n\t= Bottom of ladder\n\tM,I,K,E are the possible players");
    for(finish=0;finish<pnum;){//does everything until the last person wins
        for(a=0;a<pnum;a++){// swithces players
            if(item[0][a]!='X'){//to know if that player has already finished the gamae
                i=item[1][a];
                j=item[2][a];
                ta[i][j]=0;
                printf("\nPlease press any key to roll the dice.");//dice
                getch();
                move=rand()%6+1;
                for(ctr=0;ctr<3;ctr++){//generates three snakes of different length and making sure that they don't fall off the table.
                    do{
                        y=rand()%10;
                        z=rand()%10;
                        snakes[ctr][0]=y;
                        snakes[ctr][1]=z;
                    }while(ta[y][z]!=0 || y==9);
                    ta[y][z]='^';
                    do{
                        do{
                            w=rand()%10;
                            x=rand()%10;
                        }while(w<=y);
                        snakes[ctr][2]=w;
                        snakes[ctr][3]=x;
                    }while(ta[w][x]!=0);
                    ta[w][x]='v';
                }
                for(ctr2=0;ctr2<3;ctr2++){//generates three snakes of different length and making sure that they don't fall off the table.
                    do{
                        b=rand()%10;
                        c=rand()%10;
                        ladders[ctr2][0]=b;
                        ladders[ctr2][1]=c;
                    }while(ta[b][c]!=0 || b==9);
                    ta[b][c]='H';
                    do{
                        do{
                            d=rand()%10;
                            e=rand()%10;
                        }while(d<=b);
                        ladders[ctr2][2]=d;
                        ladders[ctr2][3]=e;
                    }while(ta[d][e]!=0);
                    ta[d][e]='=';
                }
                printf("\n Player %c can move: %i step(s)\n", item[0][a],move);
                if(i%2==0){
                    j=j-move;
                    if(j<0 && i!=0){
                        adif=0-j;
                        i--;
                        adif;
                        j+=adif*2+1;
                    }
                    else if(i==0 && j<=0){
                        if(item[0][a]!='X'){
                            finish++;
                            printf("Place %i. Player %c finished the game.\n",finish, item[0][a]);
                            item[0][a]='X';
                            display(ta);
                        }
                    }
                }
                else if(i%2==1){//Moves based on dice and row
                    j=j+move;
                    if(j>9 && i!=0){
                        adif=j%9;
                        i--;
                        adif;
                        j-=adif*2-1;
                    }
                    else if(i==0 && j<=0){
                        if(item[0][a]!='X'){//Moves based on dice and row
                            finish++;
                            printf("Place %i: Player %c finished the game\n",item[0][a]);
                            item[0][a]='X';
                            display(ta);
                        }
                    }
                }
            }
            if(item[0][a]!='X'){//checking if eaten
                for(ctr=0;ctr<3;ctr++){
                    y=snakes[ctr][0];
                    z=snakes[ctr][1];
                    w=snakes[ctr][2];
                    x=snakes[ctr][3];
                    b=ladders[ctr][0];
                    c=ladders[ctr][1];
                    d=ladders[ctr][2];
                    e=ladders[ctr][3];
                    if(i==y && j==z ){
                        printf("\n Player %c was eaten by a snake! From (%i,%i) moved to (%i,%i) \n",item[0][a],y,z,w,x);
                        ta[w][x]=item[0][a];
                        item[1][a]=w;
                        item[2][a]=x;
                        flag=1;
                        ctrstore=ctr;
                        break;
                    }
                    else if (i==d && j==e){
                        printf("\n Player %c climbed up a ladder! From (%i,%i) moved to (%i,%i)\n",item[0][a],d,e,b,c);
                        ta[d][e]=0;
                        ta[b][c]=item[0][a];
                        item[1][a]=b;
                        item[2][a]=c;
                        flag=1;
                        ctrstore1=ctr;
                        break;
                    }
                else{//moves
                        ta[i][j]=item[0][a];
                        item[1][a]=i;
                        item[2][a]=j;
                    }
                }
                display(ta);
            }//erases ladders
            for(ctr=0;ctr<3;ctr++){
                b=ladders[ctr][0];
                c=ladders[ctr][1];
                d=ladders[ctr][2];
                e=ladders[ctr][3];
                if(flag==1 && ctrstore1==ctr){
                    ta[b][c]=0;
                    flag=0;
                }
                else{
                    ta[b][c]=0;
                    ta[d][e]=0;
                    flag=0;
                }
                ta[b][c]=0;
                ta[d][e]=0;
                for(i=0;i<2;i++){
                    ladders[ctr][i]=0;
                }
            }//erases snakes
            for(ctr=0;ctr<3;ctr++){
                y=snakes[ctr][0];
                z=snakes[ctr][1];
                w=snakes[ctr][2];
                x=snakes[ctr][3];
                if(flag==1 && ctrstore==ctr){
                    ta[w][x]=0;
                    flag=0;
                }
                else{
                    ta[w][x]=0;
                    ta[y][z]=0;
                    flag=0;
                }
                for(i=0;i<2;i++){
                    snakes[ctr][i]=0;
                }
            }
        }
    }

}

void display(char table[10][10]){//displays
    //201 203 187 188 185 204 205 206 186
    int i,j;
    printf("%c",201);
    for(i=0;i<9;i++)
        printf("%c%c%c%c",205,205,205,203);
    printf("%c%c%c%c\n",205,205,205,187);

    for(i=0; i<10; i++){
        for(j=0;j<10;j++){
            printf("%c ",186);
            printf("%c ",table[i][j]);
        }
        if(i<9){
            printf("%c\n%c",186,204);
            for(j=0;j<9;j++)
                printf("%c%c%c%c",205,205,205,206);
            printf("%c%c%c%c\n",205,205,205,185);
        }
    }

    printf("%c\n%c",186,200);
    for(i=0;i<9;i++)
        printf("%c%c%c%c",205,205,205,202);
    printf("%c%c%c%c\n",205,205,205,188);
}
