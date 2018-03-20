#include<iostream>
using namespace std;
#include<queue>
#include<unordered_map>
unordered_map<int,int> myMap;
int printBFS(int *edges[],int n,int sv,int ev,bool *visited)
{
    queue<int> q;
    q.push(sv);
     int flag=0;
    while(!q.empty())
    {
        sv=q.front();
        visited[sv]=true;
        q.pop();

        ///cout<<sv<<" ";
        for(int i=0;i<n;i++)
        {
            if(edges[sv][i]==1&&!visited[i])
            {
                myMap[i]=sv;
                if(i==ev)
                {
                    flag=1;
                    break;
                }
            }

        }
        if(flag) break;

    }
    if(flag) return 1;
    else return flag;
    ///cout<<endl;

}
void printMap(int v1,int v2)
{
    int temp=v2;
    cout<<v2<<" ";
    while(v2!=v1)
    {
        cout<<myMap[v2]<<" ";
        v2=myMap[v2];

    }
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
    int v1,v2;
    cin>>v1>>v2;
   /// print(edges,n,0,visited);

   int ans= printBFS(edges,n,v1,v2,visited);
   if(ans==0) return 0;
   else
    printMap(v1,v2);
    ///delete memory now

}

