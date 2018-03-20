#include<iostream>
using namespace std;
#define LL long long int
#include<climits>
#include<cmath>

LL balancedBT(int n)
{
    if(n==1) return 1;
    if(n==2) return 3;

    LL ans =(balancedBT(n-1)*(balancedBT(n-2)+balancedBT(n-1)) )%10000000+ (balancedBT(n-2)*balancedBT(n-1))%10000000;

    return ans%10000000;



}

int main()
{
    cout<<balancedBT(4)<< " " ;
    cout<<balancedBT(8)<<" ";
    return 0;

}
