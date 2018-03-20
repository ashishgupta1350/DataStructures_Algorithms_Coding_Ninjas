#include<iostream>
using namespace std;
#define LL long long int
#include<climits>
//#include<<limits>
LL minCount_Memo(int ,int *);
LL minCount(int n)
{
    int *ans=new int [n+1];
    for(int i=0;i<=n;i++)
    {
       /// cout<<"value of i is : "<<i<<endl;
        ans[i]=INT_MAX;


    }
    ans[0]=0;
    ans[1]=1;
    return minCount_Memo(n,ans);

}/*
LL minCount(int n)
{
    if(n==1||n==0) return n;

    LL myAns=INT_MAX;

    LL i=1;
    while(i*i<=n)
    {
        LL x=1+minCount(n-i*i);
        if(x<myAns)
        {
            myAns=x;
        }
        i++;
    }
    return myAns;

*/
LL minCount_Memo(int n,int * ans)
{
    if(n==1||n==0) {
            cout<<"here"<<endl;
            return ans[n];

    }

    LL myAns=INT_MAX;

    LL i=1;
    while(i*i<=n)
    {
        if(ans[n-i*i]==INT_MAX)
            ans[n-i*i] =minCount_Memo(n-i*i,ans);
        if(ans[n-i*i]<myAns)
        {
            myAns=1+ans[n-i*i];
        }
        i++;
    }
    ///cout<<myAns<<" : "<<endl;
    ans[n]=myAns;
    return myAns;

}
int main()
{

    cout<<minCount(1000)<<endl;
       cout<<minCount(100000)<<endl;
    return 0;
}
