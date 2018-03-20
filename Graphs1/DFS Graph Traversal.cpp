
#include<iostream>
using namespace std;
#include<queue>

void print(int *edges[],int n,int sv,bool *visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(visited[i])
            continue;
        if(edges[sv][i]==1)
        {
            print(edges,n,i,visited);
        }
    }
}

void printBFS(int *edges[],int n,int sv,bool *visited)
{
    queue<int> q;
    q.push(sv);
    while(!q.empty())
    {
        sv=q.front();
        visited[sv]=true;
        q.pop();
        cout<<sv<<" ";
        for(int i=0;i<n;i++)
        {
            if(edges[sv][i]==1&&!visited[i])
            {
                q.push(i);

            }

        }

    }
    cout<<endl;
    return;
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
   /// print(edges,n,0,visited);

    printBFS(edges,n,0,visited);
    ///delete memory now

}
