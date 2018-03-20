#include<iostream>
using namespace std;
#define LL long long int
LL fibHelper(int n,LL *ans)
{
    if(n==0||n==1)
    {
        return ans[n];
    }
    if(ans[n-1]==-1)
    {
        ///calculate and store ans[n-1]
        ans[n-1]=fibHelper(n-1,ans);

    }
    if(ans[n-2]==-1)
    {
        ///calculate and store ans[n-2]
        ans[n-2]=fibHelper(n-2,ans);

    }
    ans[n]=ans[n-1]+ans[n-2];
    return ans[n];


}
LL fibonacci(int n)
{
    LL* ans=new LL [n+1];
    for(int i=0;i<=n;i++)
    {
        ans[i]=-1;

    }
    ans[0]=1;
    ans[1]=1;
    LL x= fibHelper(n,ans);
    delete []ans; ans=NULL;
    return x;
}
LL fib_Best(int n)
{
    int *ans=new int [n+1];
    ans[0]=1;ans[1]=1;
    for(int i=2;i<=n;i++)
    {
        ans[i]=ans[i-1]+ans[i-2];


    }
    return ans[n];
}
int main()
{
    cout<<fib_Best(10)<<endl;

    return 0;
}
