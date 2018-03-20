#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
int main()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i*i);

    }
    ///vector<int>::iterator it=v.begin();
    //cout<<*v.find(it)<<endl;
    for(auto it=v.begin();it!=v.end();)
    {

        cout<<*it<<" , ";
        v.erase(it);
    }

    cout<<endl<<" The size of vector is : "<<v.size()<<endl;
    unordered_map<int,bool> myMap;
    for(int i=0;i<10;i++)
    {

        myMap[i*i]=true;

    }
    unordered_map
    <int,bool>::iterator it;
    for( it=myMap.begin();it!=myMap.end();it++)
    {
        cout<<it->first<<" , ";
    }
    cout<<endl;

    return 0;

}
