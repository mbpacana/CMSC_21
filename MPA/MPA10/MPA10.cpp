#include<iostream>
using namespace std;
#include <string.h>
#include<stdio.h>
class Bignum{
private:
    char num[1000];
    int size;
public:
    Bignum();
    Bignum(char[1000]);
    Bignum(int);
    Bignum AddBig(Bignum,Bignum);
    Bignum SubBig(Bignum,Bignum);
    string MultBig(string);
    string DivBig(string);
    void display();
    int Limit(char[1001]);
};
int main(){//main
  char s1[1000],s2[1000];
  Bignum ans;
  int i=0;
    cin>>s1>>s2;
    Bignum n1(s1),n2(s2);
    //ans=n1.AddBig(n2,ans);
    //ans.display();
    cout<<endl;
    ans=n1.SubBig(n2,ans);
    ans.display();
    return 0;
}
Bignum::Bignum(){
    num[0]='\0';
    size=0;
}
Bignum::Bignum(char num[1000]){
    strcpy(this->num,num);
    size=strlen(this->num);
    //cout<<this->num;
}
Bignum::Bignum(int num){//baliki ni
    //this->num=num;
    //cout<<this->num;
}
void Bignum::display(){
    cout<<num;
}
Bignum Bignum::SubBig(Bignum n2,Bignum ans){
    cout<<"potato"<<ans.num<<ans.num<<endl;
int lim1,lim2,j,i,lim3, sum,carry,k,big=0,flag=0,temp;
    lim1=size-1;
    lim2=n2.size-1;
    cout<<lim1<<" "<<lim2<<endl;
    for(i=0;i<1001;i++){
        ans.num[i]=0;
    }
    ans.num[i]='\0';
    cout<<num<<" "<<n2.num<<" "<< ans.num;
    if(strcmp(num,n2.num)==0){
        ans.num[0]='0';
        ans.num[1]='\0';
        return ans;
    }
    else if(strcmp(num, n2.num)<0){
        cout<<num<<n2.num;
        flag=1;
        for(i=0;i<1000;i++){
            ans.num[i]=num[i];
            num[i]=n2.num[i];
        }
        for(i=0;i<1000;i++){
            n2.num[i]=ans.num[i];
        }
        carry=lim1;
        lim1=lim2;
        lim2=carry;
        cout<<num<<n2.num;
    }
    for(i=0;lim1>=0;lim1--,lim2--,i++){//subtaracts the second array from the first aray
            if (lim2<0 && lim1>=0){//If the second one is shorter, just copy the first arrays remaining numbers
                    cout<<"shorter ang second"<<endl;
                sum=num[lim1]-48;
            }
            else{
                cout<<"nisulod sa else"<<endl;
                if(num[lim1]<n2.num[lim2]){//if the first array was less than the second
                    cout<<"borrowing"<<endl;
                    num[lim1]=(num[lim1])+10;
                    j=1;
                    while(num[lim1-j]==48){//If the one next to it where you 'borrow' is zero, automatically turn it to 9
                        num[lim1-j]=57;
                        j++;
                    }
                    num[lim1-j]=num[lim1-j]-1;// If it isn't a zero you subtract 1 from it
                }
                cout<<"whyyyyy"<<sum<<num[lim1]-48<<num[lim2]-48<<endl;
                sum=(num[lim1]-48)-(num[lim2]-48);//continue normally
                cout<<sum<<num[lim1]-48<<num[lim2]-48<<endl;
            }
            ans.num[i]=sum+48;//add 48 since im using a string of characters
        }
        if(i>1){//Since I stored them right to left there is a possibility that the answers will be "0001" when displayed. I cancel out leading zeroes
            while(ans.num[i-1]==48){
                i--;
                if(i==1 && ans.num[i-1]==48){//In case zero really is the answer
                    i=1;
                    break;
                }
            }
        }
        ans.num[i]='\0';// puts a limit where it should stop
        lim3=Limit(ans.num);
        for(i=0; i<lim3; i++,lim3--){
            temp=ans.num[i];
            ans.num[i]= ans.num[lim3];
            ans.num[lim3]=temp;
        }
        if(flag==0){//the display depends if the answer is a positive or a negative
            cout<<"\n The answer is "<<ans.num;
        }
        else{
            cout<<"\n The answer is -%s"<<ans.num;
        }
}
Bignum Bignum::AddBig(Bignum n2,Bignum ans){
    //cout<<num<<n2.num;
    int lim1,lim2,i,lim3, sum,carry,k,big=0,flag=0,temp;
    for(i=0;i<1001;i++){
        ans.num[i]=0;
    }
    ans.num[i]='\0';
    //cout<<"~"<<ans<<"- "<<num<<"= "<<n2.num;
    //cout<<" basically"<<n2.num<<"and"<<num;
    lim1=size-1;
    lim2=n2.size-1;
    //cout<<lim1<<" - "<<lim2;
    for(i=0,k=0;lim1>=0 || lim2>=0;lim1--,lim2--,i++,k++){
        //cout<<lim1<<" - "<<lim2<<endl;
        if (lim1<0){//If either of the two is shorter just copy the remaining of the other one
            sum=n2.num[lim2]-48;
            //cout<<sum<<" 1~\n";
        }
        else if(lim2<0){//Normally, the numbers are just added
            sum=num[lim1]-48;
            //cout<<sum<<" 2~\n";
        }
        else{//If the sum is greater than or equal to ten we have to do a carry over
            sum=(num[lim1]-48)+(n2.num[lim2]-48);
            //cout<<(num[lim1]-48)<<"+"<<(n2.num[lim2]-48)<<" The sum is "<<sum<<lim1<<" "<<lim2<<" 3~\n";
        }
        if (ans.num[i]+sum>=10){//The current value of an array if added to the sum will go here
            //cout<<"nisud diri "<<sum<<" 3~\n"<<i<<endl;
            sum=ans.num[i]+sum;
            //cout<<"The sum is now "<<sum<<endl;
            carry=1;//Gets the carry value
            sum=sum%10;//Gets the non carry value
            if(lim1<=0 && lim2<=0){//if both are at they're last numbers
               // cout<<"same length and both ending"<<endl;
                ans.num[i+1]=carry+48;
                ans.num[i]=0;
                //cout<<"dapat 1 ni "<<ans.num[i+1]<<endl;
                k=i+1;//special case to know where to put the '\0'
            }
            else{//puts the carry directly in the answee
                ans.num[i+1]=carry;
                ans.num[i]=0;
            }
        }
       // cout<<ans.num[i]<<"-"<<sum<<"-"<<i<<"-"<<k<<endl;
        ans.num[i]=ans.num[i]+sum+48;
        //cout<<ans.num[i]<<"-"<<sum<<"-"<<i<<"-"<<k<<endl;
    }
        //cout<<"The ans is"<<ans.num[k]<<k<<"~!~"<<i<<endl;
         ans.num[k]='\0';//to tell the string where to stop
         //cout<<ans.num;
         lim3=Limit(ans.num);
         //cout<<"the limit is"<<lim3<<endl;
        for(i=0; i<lim3; i++,lim3--){//reversing the string
            temp=ans.num[i];
            ans.num[i]= ans.num[lim3];
            ans.num[lim3]=temp;
        }
        //cout<<"\n The answer is "<<ans.num<<endl;
        return ans;
}
int Bignum::Limit(char  n[1001]){//Finds out the limit or the certain length of a string
    int i,lim;
    for (i=0;n[i]!='\0';i++);
    i--;
    lim=i;
    return lim;
}



