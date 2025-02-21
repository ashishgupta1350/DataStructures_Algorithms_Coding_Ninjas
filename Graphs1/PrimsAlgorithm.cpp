#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int findMinVertex(bool* visited,int* weight,int V){
    int x=INT_MAX;
    int y=-1;
    for(int i=0;i<V;i++){
        if(weight[i]<x && visited[i]==false){
            x=weight[i];
            y=i;
        }
    }
    
    return y;
}

void prims(int** adjMat,int V){
    bool* visited=new bool[V];
    int* parent=new int[V];
    int* weight=new int[V];
    
    for(int i=0;i<V;i++){
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    
    parent[0]=-1;// WE CONSIEDER IT TO BE THE SOURCE
    weight[0]=0;
    
    for(int i=0;i<V;i++){
        // pick vertex with min weight which is unvisited
        int x=findMinVertex(visited,weight,V);
        
        visited[x]=true;
        
        // explore unvisited neighbours
        
        for(int i=0;i<V;i++){
            if(i==x)
                continue;
            
            if(adjMat[x][i]!=0){
                //adj
                if(visited[i]==true)
                    continue;
                if(adjMat[x][i]<weight[i]){
                    //update weight and parent
                    // weight here is our greedy parameter to find way wid min cost
                    weight[i]=adjMat[x][i];
                    parent[i]=x;
                }
                
            }
            
            
        }
        
        
        
    }
    
    
    for(int i=1;i<V;i++){
        
        if(i<parent[i])
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        else{
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
    }
    
    
    
    
    
}
int main()
{int V,E;
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
    prims(adjMat,V);
    
    
    for(int i=0;i<V;i++){
        delete [] adjMat[i];
    }
    delete [] adjMat;
    
    return 0;
}
