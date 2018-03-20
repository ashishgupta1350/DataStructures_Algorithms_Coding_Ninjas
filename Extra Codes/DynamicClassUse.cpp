#include<iostream>
using namespace std;
#include"Dynamic_array_class.cpp"

int main()
{
    DynamicArray a;
    for(int i=0;i<7;i++)
    {
        a.add(i);

    }
     // DynamicArray b(a);
   DynamicArray b(a);
  DynamicArray c;

    cout<<"Here"<<endl;
///
    cout<<"here here"<<endl;
    ///b.add(0,1000);
    a.print();
    ///a.add(1,100);
    b.print();

///    c.print();
    return 0;


}
