#include<iostream>
using namespace std;
#include<climits>
#include<limits>
#define LL long long int
LL minSteps(int n)
{

    LL *ans=new LL[n+1];
    ans[0]=INT_MAX;
    ans[1]=0;
    LL x,y,z;

    for(int i=2;i<=n;i++)
    {
       x=y=z=INT_MAX;
       x=ans[i-1];
       if(i%2==0)
       {
           y=ans[i/2];
       }
       if(i%3==0)
       {
           z=ans[i/3];
       }
       ans[i]=1+min(x,min(y,z));


    }

    LL ret= ans[n];
    delete []ans;
    ans=NULL;
    return ret;

}
int main()
{
    cout<<minSteps(11)<<endl;
    cout<<minSteps(10)<<endl;
    return 0;


}
