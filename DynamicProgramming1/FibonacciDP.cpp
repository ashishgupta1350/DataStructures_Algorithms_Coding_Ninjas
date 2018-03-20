#include<iostream>
using namespace std;
#define LL long long int

LL Fib(int n,LL *memo)
{
    if(n<0) return -1;
    if(n==0||n==1)
    {
        return n;
    }
    /// this means n is greater than 1
   /// int x=0,y=0;
    if(memo[n-1]==0)
    {
        memo[n-1]=Fib(n-1,memo);

    }
    if(memo[n-2]==0)
    {
        memo[n-2]=Fib(n-2,memo);
    }
    memo[n]=memo[n-1]+memo[n-2];
    return memo[n];
   /*int x= Fib(n-1,memo);
   int y=Fib(n-2,memo);
   return x+y;*/
}
LL calculateFibonacci(int n)
{
    LL *memo=new LL [n+1];
    for(int i=0;i<n+1;i++)
    {

        memo[i]=0;
    }
    memo[1]=1;
    return Fib(n,memo);

}
LL Fib_DP(int n)
{
    if(n<0) return -1;
    LL *Ans=new LL[n+1];
    Ans[0]=0;
    Ans[1]=1;
    int i=2;
    while(i<=n)
    {
        Ans[i]=Ans[i-1]+Ans[i-2];
        i++;

    }
    return Ans[n];


}

int main()
{
    int n;
    ///cout<<"Enter number  :  ";
    for(int i=0;i<10;i++)
    {
        cout<<Fib_DP(i)<<endl;

    }

    return 0;
}
