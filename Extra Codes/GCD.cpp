#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void print(int *a,int n){

    for(int i=0;i<n;i++) cout<<a[i]<<" ";


}
int order(int *a,int n,int v1,int v2,int *printer,int k)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==v1)
        {
            printer[k]=v1;printer[k+1]=v2;k=k+2;
            break;
        }
        if(a[i]==v2)
        {
            printer[k]=v1;printer[k+1]=v2;k=k+2;
            break;

        }

    }
    ///store it in an array and sort it and then print it...
    return k;

}

int main() {
    int n;
    cin>>n;
   int *a=new int [n];
    int *b=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    int *diffarray=new int[n-1];/// the size is n-1;
    int j=0;
    for(int i=0;i<n-1;i++)
    {
        diffarray[j]=abs(b[i+1]-b[i]);
        j++;
    }
    long long int min=10000000;
   for(int i=0;i<n-1;i++)
   {
    if(diffarray[i]<min){
        min=diffarray[i];
    }
   }
    int k=0;int *printer=new int[2*n+1];
    for(int i=0;i<n-1;i++)
    {
        if(diffarray[i]==min)
        {
            k= order(a,n,b[i],b[i+1],printer,k);


        }


    }
    sort(printer,printer+k);
    print(printer,k);

    return 0;
}
