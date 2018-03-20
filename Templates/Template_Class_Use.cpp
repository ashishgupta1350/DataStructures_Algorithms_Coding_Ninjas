#include<iostream>
using namespace std;
#include"Class_Templates.cpp"
#include<string>

int main()
{
    //Pair<int,int> p;p.setX(10);p.setY(20);
    Pair <int ,string > p;
    p.setX(10);p.setY("Daum, did i just do that?");
    Pair<Pair<int,string>,char> p2;
    p2.setY('D');
    p2.setX( p);
    cout<<"P is : ";
    cout<<p.getX()<< " "<<p.getY()<<endl;
    cout<<"p2 is : ";
    cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY()<<endl;//this is awesome, output change nhi kar rhe, just <pair<int,int>,pair<int,int>>
    return 0;
}
