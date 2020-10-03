#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int pickVertexWithMinDistance(bool* visited,int* distance,int V){
    int x=-1;
    for(int i=0;i<V;i++){
        if(!visited[i] &&(x==-1 || distance[i]<distance[x] )){
            x=i;
        }
    }
    return x;
}
void dijkstras(int** adjMat,int V){
    bool* visited=new bool[V];
    int* distance =new int[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    for(int i=0;i<V;i++){
        int x=pickVertexWithMinDistance(visited,distance,V);
        visited[x]=true;
        for(int j=0;j<V;j++){
            
            if(adjMat[x][j]!=0){
                //they are adj
                if(visited[j]==true)
                    continue;
                if(distance[x]+adjMat[x][j]<distance[j]){
                    distance[j]=distance[x]+adjMat[x][j];
                }
            }
        }   
    }
    
    for(int i=0;i<V;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete [] visited;
    delete [] distance;
    
}
int main()
{
 int V,E;
    cin >> V >> E;
    
    int** adjMat=new int*[V];
    for(int i=0;i<V;i++){
        adjMat[i]=new int[V];
        for(int j=0;j<V;j++){
            adjMat[i][j]=0;
        }
    }
    
    for(int i=0;i<E;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        adjMat[v1][v2]=w;
        adjMat[v2][v1]=w;
        
        
    }
    cout<<endl;
    dijkstras(adjMat,V);
    
    
    for(int i=0;i<V;i++){
        delete [] adjMat[i];
    }
    delete [] adjMat;
    
    return 0;
}
