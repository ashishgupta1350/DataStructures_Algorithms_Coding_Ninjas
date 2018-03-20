#include<iostream>
using namespace std;
#include"PriorityQueueClass.cpp"

int main()
{
    PriorityQueue pq;
    pq.Insert(2);
    pq.Insert(8);
    pq.Insert(6);
    pq.Insert(5);
    pq.Insert(11);
    pq.Insert(7);
    pq.Remove();

        cout<<pq.getMin();


    return 0;
}
