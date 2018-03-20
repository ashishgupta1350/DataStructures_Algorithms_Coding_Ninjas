#include<iostream>
using namespace std;
#include"MapClass.h"
int main()
{
    myMap<int> M;
    M.Insert("abc",1000);
    M.Insert("def",200);
    M.Insert("ghi",2000);
    M.Insert("abcd",3100);
    M.Insert("cba",2500);
    cout<<"size of the map is : "<<M.getSize()<<endl<<endl;

    cout<<M.getValue("def")<<endl<<endl;
   cout<<"Searching for abc"<<endl;
    cout<<M.Search("abc");
    cout<<endl;

  cout<<"removing : "<< M.Remove("abc")<<endl;

    cout<<"Searching for abc"<<endl;
    cout<<M.Search("abc");
    cout<<endl;

    return 0;
}
