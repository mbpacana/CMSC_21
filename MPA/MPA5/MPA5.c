//Michael Ervin Pacana
//I declare upon my honor that I made this mp by myself.
#include<stdio.h>
#include<time.h>
typedef struct {
    int blink, weapon, shield, hp, mp;
}player;//declaration of functions for this group
void assign(player *,int,int,int,int);
void attack(player *, player *);//function that calculates the damage
void displayitem(int,int);//function for displaying the weapons used
int main(){
    player p1,p2;//both players are declared
    int temp[4],i;
    srand((unsigned int)time(NULL));
    p1.blink=2;//blink initializations
    p2.blink=2;
    for(i=0;i<5;i++){
        temp[i]=rand()%3+1;
    }
    assign ( &p1,temp[1],temp[2],10,10);//assigning of weapons
    assign ( &p2,temp[3],temp[4],10,10);
    printf("\nPLAYER1 has acquired a"); //printing which weapons each player is using
    displayitem(p1.weapon,p1.shield);
    printf("\nPLAYER2 has acquired a");
    displayitem(p2.weapon,p2.shield);
    printf("\n");
    system(" pause");
    do {
        printf("\nPLAYER1 is wielding a"); //printing which weapons each player is using
        displayitem(p1.weapon,p1.shield);
        printf("\nPLAYER2 is wielding a ");
        displayitem(p2.weapon,p2.shield);
        printf("\n");
        printf("\nPLAYER 1's HP is %i/10 and Manna is %i/10 \nPLAYER 2's HP is %i/10 and Manna is %i/10\n",p1.hp,p1.mp,p2.hp,p2.mp);
        printf("\nIt is now Player 1's turn");
        attack(&p1,&p2);
        if(p2.hp<=0 || (p1.hp)<=0){//breaks if at least one of them dies
            break;
        }
        printf("\nPLAYER 1's HP is %i/10 and Manna is %i/10 \nPLAYER 2's HP is %i/10 and Manna is %i/10\n",p1.hp,p1.mp,p2.hp,p2.mp);
        printf("\nPLAYER1 is wielding a"); //printing which weapons each player is using
        displayitem(p1.weapon,p1.shield);
        printf("\nPLAYER2 is wielding a ");
        displayitem(p2.weapon,p2.shield);
        printf("\n");
        printf("\nIt is now Player 2's turn");
        attack(&p2,&p1);
    }while ((p1.hp)>0 && (p2.hp)>0);
    return 0;
}
void attack(player *px, player *py){
    int choice=0,shield,damage;
    if((*px).blink!=1 && (*py).blink!=1){
        (*px).blink=rand()%20+1;
        if((*px).blink==1){
            printf("\nYou have stumbled upon the Bai-a-Labi's Blink ");
        }
    }
    if((*px).blink==1){
            printf("\nCurrent player posseses Bai-a-Labi's Blink");
    }
    if((*py).mp<10){//regenerates mp
        (*py).mp=(*py).mp+2;
    }
    do{//Iterates if choice is lesser than 1 or greater than 2
        printf("\n What will you do? (Enter number of your choice) ");
        printf("\n\t1. Attack with weapon\n\t2. Kiss of the Jade Palapa\n");
        scanf(" %i", &choice);
        if (choice<1 || choice>3|| choice==2 && (*px).mp<6 ||  choice==3 &&(*px).blink!=1){
            printf("\nInvalid choice!\n");
        }
    }while (choice<1 || choice>3 || choice==2 && (*px).mp<6||  choice==3 &&(*px).blink!=1);
        if(choice==1){//If player chose to attack with weapon
            damage=(*px).weapon;
            shield=rand()%3+1;
            if(shield==1){//If shield is used
                printf("\nThe opponent successfully used their shield!\n");
                    if((*px).weapon==2 && (*py).shield==1 || (*px).weapon==3 && (*py).shield==2){
                        printf("\nOne damage point repelled to the attacker!\n");
                        damage--;
                    }
                    else if((*px).weapon==1 && (*py).shield==2 || (*px).weapon==1 && (*py).shield==3 || (*px).weapon==2 && (*py).shield==3){
                        printf("\nThe damage was repelled back to the attacker!\n");
                        damage=0-damage;
                    }
                    else if ((*px).weapon==1 && (*py).shield==1 || (*px).weapon==2 && (*py).shield==2 || (*px).weapon==3  && (*py).shield==3){
                        printf("\nThe damage was neutralized!\n");
                        damage=0;
                    }
                    else{
                        printf("But the opponent's shield can't repel your weapon.\n");
                    }
          }
          else
                printf("\nThe opponent received FULL DAMAGE!\n");
        }
        else if(choice==2){//If attacker chose to use magic
            if((*py).blink==1){//if by chance the opponent posseses the Bai a labis blink.
                printf("\n Oh no! Your Kiss of the Jade Palapa was deflected!\n");
                damage=-4;
                (*py).blink=2;
            }
            else{
                damage=4;
            }
            (*px).mp=(*px).mp-6;//when a spell is cast mana is subtracted
        }
        if(damage>0){//subtracts the hp from the corresponding player that the damage wa
            (*py).hp=(*py).hp-damage;
        }
        else if(damage<0){
            (*px).hp=(*px).hp+damage;
        }
        if((*px).hp<=0){
            printf("\n\n\nGAME OVER.\n\n\n");//prints game over
        }
        else if((*py).hp<=0){
            printf("\n\n\nGAME OVER.\n\n\n");
        }
        else{
            system("pause");
            system(" cls");
        }
}
void assign(player *px,int weapon, int shield,int hp,int mp){//assigns initial values to hp,mp,shield and blink
    (*px).weapon=weapon;
    (*px).shield=shield;
    (*px).hp=hp;
    (*px).mp=mp;
    (*px).blink=2;
}
void displayitem(int weap,int shield){//displays the weapons and shields used
    if (weap==1)
        printf(" WOODEN SWORD and a");
    else  if(weap==2)
        printf(" SILVER SCYTHE and a");
    else if(weap==3)
        printf(" DIAMOND SPEAR and a");
    if (shield==1)
        printf(" WOODEN SHIELD.");
    else if(shield==2)
        printf(" SILVER SHIELD.");
    else if (shield==3)
        printf(" DIAMOND SHIELD.");
}
