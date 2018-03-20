#include<iostream>
using namespace std;
#include"Queue_Class_T.cpp"

int main()
{
    Queue<char> q;

    for(int i='a';i<'z';i++)
    {
        q.enqueue(i);

    }
        for(int i=0;i<10;i++)
        {
            ///cout<<q.Front()<<" ";
            q.dequeue();

        }
        for(int i='a';i<='j';i++)
    {
        q.enqueue(i);

    }
       /// cout<<endl;

        cout<<"The final queue is : ";
        for(int i=0;!q.isEmpty();i++){
            cout<<q.Front()<< " ";
            q.dequeue();
        }
        cout<<endl;

    cout<<q.isEmpty()<<endl;

    return 0;
}
