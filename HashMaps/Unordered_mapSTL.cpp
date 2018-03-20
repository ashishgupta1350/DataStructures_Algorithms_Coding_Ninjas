#include<iostream>
using namespace std;
#include<unordered_map>
#include<string>
#include<vector>
vector<int> removeDuplicates(int *a,int n)
{
    vector<int> v;
    unordered_map<int,bool> seen;
    for(int i=0;i<n;i++)
    {
        if(seen.count(a[i])>0)
            continue;
        else{
            seen[a[i]]=true;
            v.push_back(a[i]);
            continue;

        }

    }
    return v;

}

int main()
{
    unordered_map<string,int> ourmap;
    unordered_map<int,int> myMap;
    for(int i=0;i<10;i++)
    {
        myMap[i*i]=i;

    }
    for(auto  it=myMap.begin();it!=myMap.end();it++)
    {
        cout<<"> "<<it->first<<"-> "<<it->second<<endl;

    }
    int a[]={1,1,3,4,4,2,3,1,5,9,9,0,1,0};
    vector<int> v=removeDuplicates(a,14);
    for(int i=0;i<v.size();i++)
    {
        cout<<v.at(i)<<" ";

    }
    cout<<endl;

    return 0;
}
