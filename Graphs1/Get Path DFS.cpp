#include <iostream>
using namespace std;
#include<vector>
vector<int>* getPath(int *edges[],int n,int sv,int ev,bool *visited)
{
   if(sv==ev){
     //make a vector
     vector<int> *v=new vector<int>;
     v->push_back(sv);
     return v;
   }
  vector<int>*temp2=NULL;
    visited[sv]=true;

    for(int i=0;i<n;i++)
    {
        if(visited[i])
            continue;
        if(edges[sv][i]==1)
        {
            vector<int>*temp=getPath(edges,n,i,ev,visited);
          if(temp!=NULL)
          {
            temp2=temp;
            break;

          }
        }
    }
  if(temp2!=NULL)
  {
    temp2->push_back(sv);

  }
  return temp2;
}


int main()
{
    int n,e;
    cin>>n>>e;
    int**edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }

    }
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;

    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;

    }
  int v1,v2;
  cin>>v1>>v2;

   /// print(edges,n,0,visited);
	vector<int> *v=getPath(edges,n,v1,v2,visited);
  if(v==NULL) return 0;

  for(int i=0;i<v->size();i++)
  {
    cout<<v->at(i)<<" ";
  }
    ///delete memory now

}


