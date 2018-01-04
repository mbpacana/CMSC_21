//I declare upon my honor that I made this mp by myself
#include <stdio.h>
int PrimeSieve(unsigned int);
void AddSubBig(char[],char[], int);
int ComboCoins(unsigned int);
int ComboCoins2(unsigned int);
int limit(char[]);
int main (){//main code
    system("color 0B");
    int ans=1,i,opr,flag=1;
    unsigned int n;
    unsigned long int ans3;
    char n1[101], n2[101];
    while (ans!=4){//Displays menu
        printf("\n\n\t1.Sieve\n\t2.Big Number\n\t3.Coin Changing\n\t4.Exit\n\n\tPlease enter the number of your choice: ");
        scanf(" %i", &ans);
        if(ans==1){//If option 1 is chosen...
            system("cls");
            printf("\nYou have selected Sieve. I will now determine the nth prime number.");
            do{
                printf("\nPlease enter a number: ");//Asks an unsigned int
                scanf(" %u", &n);
                if(n>10001){
                    printf("\nThe LIMIT is 10,000");
                }
            }while(n<1 || n>=10001);
            i=PrimeSieve(n);// sends n to the function
            printf("\n The nth prime number is %i", i);
        }
        else if(ans==2){//If option 2 is chosen
            system("cls");
            printf("\nYou have selected Big number.  Please enter 2 numbers to be added or subtracted.");
            do{//asks for input
                flag=1;
                printf("\n Please enter the first number: ");
                scanf(" %s", n1);
                printf("\n Please enter the second number: ");
                scanf(" %s", n2);
                for(i=0;n1[i]!='\0' ;i++){
                    if(n1[i]<'0'|| n1[i]>'9' || i>99){
                        flag=0;
                        break;
                    }
                }
                for(i=0;n2[i]!='\0' ;i++){
                    if(n2[i]<'0' || n2[i]>'9' || i>99){
                        flag=0;
                        break;
                    }
                }

            }while(n1[0]==48 || n2[0]==48 || flag==0);
            do{//provides options
                printf("\n\t 1. Addition\n\t 2. Subtraction \n\t Please choose the number of your choice: ");
                scanf(" %i", &opr);
            }while(opr<1 || opr>2);
            AddSubBig(n1, n2, opr);//feeds it into the function
        }
        else if(ans==3){//if option 3 is chosen
            system("cls");
            printf("\nYou have selected Coin Changing. I will now give the total number of possible combinations of coins that add up to the given amount.");
            do{//asks for input
                printf(" \nPlease enter an amount: ");
                scanf(" %u", &n);
                if (n<=0){
                    printf("\nDo you really think you can represent that amount with coins? ");
                }
            }while(n%1!=0 || n<=0 || n>100000);
            ans3=ComboCoins(n);// gives it to the function
            printf("\n The number of possible combinations: %lu", ans3);
        }
        else if (ans!=4){
            printf("\nInvalid Choice, Please select another option.");
        }
    }
    printf("\nYou have selected Exit.");//exits the program
    return 0;
}
int PrimeSieve (unsigned int n){//Uses Sieve to bring out the nth prime number
    int i,number[104730],ctr,j;
    for(i=0; i<104730; i++){//fills every number with the number of the index for easy picking
        number[i]=i;
    }
    for(i=2,ctr=0; ctr<n;i++){//starts from 2 and cancels every multiple of those not canceled
        if(number[i]!=-1){
            ctr++;//every number that is not canceled will increase the counter
            for(j=2;i*j<104730;j++){//I cancel by setting it to negative one
                number[i*j]=-1;
            }
        }
    }
    return i-1;
}
void AddSubBig(char n1[],char n2[], int opr){//Adds or subtracts two big numbers
    int i,j,lim1,lim2,lim3, sum,carry,ncarry,k,big=0,flag=0;
    char ans[101],temp;
    lim1= limit(n1);
    lim2= limit (n2);
    for(i=0;i<=101;i++){// fills the answer array with 0s
        ans[i]=0;
    }
    printf("%i %i",lim1,lim2);
    if (opr==1){//when addition opion is chosen
        for(i=0,k=0;lim1>=0 || lim2>=0;lim1--,lim2--,i++,k++){
            if (lim1<0){//If either of the two is shorter just copy the remaining of the other one
                sum=n2[lim2]-48;
            }
            else if(lim2<0){//Normally, the numbers are just added
                sum=n1[lim1]-48;
            }
            else{//If the sum is greater than or equal to ten we have to do a carry over
                sum=(n1[lim1]-48)+(n2[lim2]-48);
            }
            if (ans[i]+sum>=10){//The current value of an array if added to the sum will go here
                    sum=a   ns[j]+sum;
                    carry=1;//Gets the carry value
                    sum=sum%10;//Gets the non carry value
                        if(lim1<=0 && lim2<=0){//if both are at they're last numbers
                            ans[j+1]=carry+48;
                            k=i+1;//special case to know where to put the '\0'
                        }
                        else{//puts the carry directly in the answee
                            ans[j+1]=carry;
                        }
            }
            ans[i]=ans[i]+sum+48;
        }
        ans[k]='\0';//to tell the string where to stop
        lim3=limit(ans);
        for(i=0; i<lim3; i++,lim3--){//reversing the string
            temp=ans[i];
            ans[i]= ans[lim3];
            ans[lim3]=temp;
        }
        printf("\n The answer is %s",ans);
    }
    if (opr==2){//if subtraction was selected
        if (lim1==lim2){//if both were the same size this determines which is bigger by comparing the values from first to last until deemed the same
            for(i=0,big=0;i<=lim1;i++){
                if(n1[i]>n2[i]){
                    big=1;
                    break;
                }
                else if(n1[i]<n2[i]){
                    big=2;
                    break;
                }
            }
        }
        if(lim2>lim1 || big==2){//if the second one was bigger which means the outcome was a negative, i had to interchange them and then set a flag that would display a negative answer
            flag=1;
            for(i=0;i<100;i++){
                ans[i]=n1[i];
                n1[i]=n2[i];
            }
            for(i=0;i<100;i++){
                n2[i]=ans[i];
            }
            carry=lim1;
            lim1=lim2;
            lim2=carry;
        }
        for(i=0;lim1>=0;lim1--,lim2--,i++){//subtaracts the second array from the first aray
            if (lim2<0 && lim1>=0){//If the second one is shorter, just copy the first arrays remaining numbers
                sum=n1[lim1]-48;
            }
            else{
                if(n1[lim1]<n2[lim2]){//if the first array was less than the second
                    n1[lim1]=(n1[lim1])+10;
                    j=1;
                    while(n1[lim1-j]==48){//If the one next to it where you 'borrow' is zero, automatically turn it to 9
                        n1[lim1-j]=57;
                        j++;
                    }
                    n1[lim1-j]=n1[lim1-j]-1;// If it isn't a zero you subtract 1 from it
                }
                sum=(n1[lim1]-48)-(n2[lim2]-48);//continue normally
            }
            ans[i]=sum+48;//add 48 since im using a string of characters
        }
        if(i>1){//Since I stored them right to left there is a possibility that the answers will be "0001" when displayed. I cancel out leading zeroes
            while(ans[i-1]==48){
                i--;
                if(i==1 && ans[i-1]==48){//In case zero really is the answer
                    i=1;
                    break;
                }
            }
        }
        ans[i]='\0';// puts a limit where it should stop
        lim3=limit(ans);
        for(i=0; i<lim3; i++,lim3--){
            temp=ans[i];
            ans[i]= ans[lim3];
            ans[lim3]=temp;
        }
        if(flag==0){//the display depends if the answer is a positive or a negative
            printf("\n The answer is %s",ans);
        }
        else{
            printf("\n The answer is -%s",ans);
        }
    }
}
int limit(char  n[]){//Finds out the limit or the certain length of a string
    int i,lim;
    for (i=0;n[i]!='\0';i++);
    i--;
    lim=i;
    return lim;
}
int ComboCoins(unsigned int n){//Function for the third option
    int  coin[3]={5,10,20},ans,i,j,lim,sum,ten,ans2;// I noticed that the total combination is composed of 4 parts each with different formulas
    unsigned long int ctr;
    if (n==0){//Although I do not accept '0' as input because it obviously cannot be represented by any combinations, this is essential when the code runs.
        return 1;
    }
    else{//The first part is the "1" in which all numbers poses so I didn't bother to put it but rather just added one after everything
        for(i=0,ctr=0; i<3;i++){
            ans=n/coin[i];
            if(ans<1){//This is so that the code wont go further if the prior has found it to have less than 1(because 2 five's are needed to make a 10 and same goes for 20 and 40)
                ctr=ctr+ans;
                break;
            }
            else if(i==1){//I noticed that for the second part of the formula, it is just the square or the square plus the quotient when divided by ten
                if(n%10>4){
                    ans=ans*ans+ans;
                }
                else{
                    ans=ans*ans;
                }
            }
            else if(i==2){//Here is the tedious part. For the last part of the formula you need to subtract 20 (if its greater than 20) and input the difference to the this same program. I cannot make this function call it self since it will accumulate so instead I run the difference in a mirror function so that it does not accumulate.
                for (j=1,sum=0; j<=ans; j++){
                        if(n%20==0 && n>20 && j==ans){//break if divisible by 40 so that it won't feed a difference of zero to the mirror function
                            break;
                        }
                        ten=n-(20*j);
                        sum=sum+ComboCoins2(ten);
                }
                ans=sum;
            }

                ctr=ctr+ans;
        }
    }
    return ctr+1;
}
int ComboCoins2(unsigned int n){//Identical t the first except without the "20's"  tab because all  input is either 20 or less and also I added that if it detects 20, it returns 10 automatically. No matter how I call the function itself in the above function it seems to add a certain amount to the one desired so i decided to make a duplicate and let it call it's duplicate.
    int ctr, coin[3]={5,10,20},ans,i,j,lim,sum,ten,ans2;
    if (n==20){
        return 10;
    }
    else{
        for(i=0,ctr=0; i<2;i++){
            ans=n/coin[i];
            if(ans<1){
                ctr=ctr+ans;
                break;
            }
            else if(i==1){
                if(n%10>4){
                    ans=ans*ans+ans;
                }
                else{
                    ans=ans*ans;
                }
            }
            ctr=ctr+ans;
        }
    }
    return ctr+1;
}
