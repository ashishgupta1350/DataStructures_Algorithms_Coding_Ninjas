#include <iostream>
using namespace std;

bool hasPath(int *edges[],int n,int sv,int ev,bool *visited)
{

    visited[sv]=true;
  if(edges[sv][ev]==1) return true;

  /// else part

    for(int i=0;i<n;i++)
    {
        if(visited[i])
            continue;
        if(edges[sv][i]==1)
        {
            bool ans=hasPath(edges,n,i,ev,visited);
          if(ans==true)
            return true;
        }
    }
  return false;
}

int main() {
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
  bool ans=hasPath(edges,n,v1,v2,visited);
  if(ans=true)
    cout<<"true";
  else cout<<"false";


  return 0;
}
