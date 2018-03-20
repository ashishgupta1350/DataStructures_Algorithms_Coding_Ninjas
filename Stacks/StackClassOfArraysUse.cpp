#include<iostream>
using namespace std;
#include"Dynamic_Stack_Class.cpp"
#include<string>
int main()
{--
    StackUsingArrays<string> s;
    for(int i=0;i<10;i++)
    {
        s.push("hey");
    }

    ///s.push(2);
    while(!s.isempty())
    {
       cout<< s.top()<<" ";
        s.pop();
    }
    return 0;

}
