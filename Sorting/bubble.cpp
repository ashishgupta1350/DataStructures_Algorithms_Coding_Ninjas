#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[],int n)
{
    int flag,p=0;
    for(int i=0;i<n-1;i++)
    {   flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                flag=1;
                p++;
            }
        }
        if(flag==0)
        {
            break;
        }
    }

    cout<<"Array is sorted in"<<" "<<p<<" "<<"swaps."<<endl;
    cout<<"First Element:"<<" "<<a[0]<<endl;
    cout<<"Last Element:"<<" "<<a[n-1]<<endl;
    
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubble_sort(a,n);
    cout<<"Sorted array is:"<<" ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
