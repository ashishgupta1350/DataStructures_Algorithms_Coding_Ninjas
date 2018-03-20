#include<iostream>
using namespace std;
#include<queue>
#include<vector>
vector<int> sortedArray;
int main()
{
    priority_queue<int> myPQ;
    myPQ.push(10);
    myPQ.push(60);
    myPQ.push(20);
    myPQ.push(50);
    myPQ.push(100);
    myPQ.push(40);

    while(!myPQ.empty())
    {
        cout<<myPQ.top()<<" ";
        myPQ.pop();

    }

/*
    cout<<"Enter a K-sorted array, first no of elements then the elements then the value of k :  "<<endl;
    int numElements;
    cin>>numElements;
    int *arr=new int[numElements];
    for(int i=0;i<numElements;i++)
    {
        cin>>arr[i];

    }
    int k;cin>>k;
    priority_queue<int> pq;
    if(k==0){
        cout<<"The array must be sorted: "<<endl;

    }
    int i;
    ///int &index=i;
    for( i=0;i<k;i++)
    {
        pq.push(arr[i]);

    }
    int sortedArrayIndex=0;
    while(pq.size())
    {

        sortedArray.push_back(pq.top());
        ///sortedArrayIndex++;
        pq.pop();
        if(i<numElements)
        {
            pq.push(arr[i]);
            i++;
        }


    }
    for(int i=0;i<sortedArray.size();i++)
    {
        cout<<sortedArray[i]<<" ";
    }
    cout<<endl;
*/    return 0;

    }
