#include<iostream>
using namespace std;
#include"Stack_LL.h"

int main()
{
    StackUsingLL<int> s;
    for(int i=0;i<10;i++)
    {

        s.push(i+1);
    }

    for(int i=0;i<10;i++)
    {

        cout<<s.top()<<" ";
        s.pop();
    }
    s.pop();
    cout<<s.isempty()<<endl;


    return 0;
}
