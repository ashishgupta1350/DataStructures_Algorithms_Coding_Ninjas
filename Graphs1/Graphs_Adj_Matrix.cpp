#include<iostream>
using namespace std;
void print(int **edges,int n,int sv,bool *visited)
{
    cout<<sv<<endl;///because this is how i am supposed to print this thing
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1)
            if(!visited[i])
               print(edges,n,i,visited);

    }


}

int main()
{
    ///declaration of variables
    ///input
    int n;
    int e;
    cin>>n>>e;
    int **edges=new int* [n];
    for(int i=0;i<n;i++)
    {
        //for every edge make an array
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;

        }

    }
    for(int i=0;i<e;i++)
    {
        int father,son;
        cin>>father>>son;///father son node relation
        edges[father][son]=1;
        edges[son][father]=1;

    }
    cout<<"Here"<<endl;

    ///print graph in DFS mode
    bool * visited =new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    print(edges,n,0,visited);

    ///destructor
    delete[]visited;
    visited=NULL;
    for(int i=0;i<n;i++)
    {
        delete []edges[i];

    }
    delete[]edges;
    edges=NULL;

    return 0;
}
