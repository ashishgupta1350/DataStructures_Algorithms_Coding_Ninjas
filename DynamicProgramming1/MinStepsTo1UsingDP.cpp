#include<iostream>
#include<climits>
#include<limits>
using namespace std;

int minStepsTo1_DP(int n)
{
    int *dp=new int [n+1];
    /// this dp[i] represents min steps taken by number i to reach 1
    dp[1]=0;
    int y,z;

    for(int i=2;i<=n;i++)
    {
        y=INT_MAX;
        z=INT_MAX;
        if(i%2==0)
        {
            y=dp[i/2];

        }
        if(i%3==0)
        {
            z=dp[i/3];

        }
        dp[i]=1+min(dp[i-1],min(z,y));
    }
    return dp[n];
}

int main()
{



}
