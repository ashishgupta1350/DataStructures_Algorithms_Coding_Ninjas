#include<iostream>
using namespace std;
#include"HashMapsClass_TrialAndError.cpp"
#include<string>
int main()
{
    HashMap<string> h;
    h.Insert(10,"abc");
    h.Insert(20,"def");
    h.Insert(30,"ghi");
    h.Insert(5,"jkl");
    h.Insert(25,"MNO");


    cout<<"if Yes then 1>>>"<<h.Search(5)<<endl;

    h.printTree();

    return 0;
}
