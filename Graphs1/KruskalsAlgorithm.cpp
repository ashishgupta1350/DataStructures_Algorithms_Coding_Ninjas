#include <iostream>
#include<algorithm>
using namespace std;

class Edge{
public:
    int source;
    int destination;
    int weight;
    
    Edge(){
        this->source=-1;
        this->destination=-1;
        this->weight=-1;
        
    }
    
    Edge(int s,int d,int w){
        this->source=s;
        this->destination=d;
        this->weight=w;
        
    }
    
};

bool wayToSort(Edge e1,Edge e2)
{ return e2.weight > e1.weight;
    
}

int getParent(int* parent,int v){
    if(parent[v]==v)
        return v;  // we want the absolute top one
    v=parent[v];
    return getParent(parent,v);
    
    
}
int main()
{
 
  int V, E;
    cin >> V >> E;
    Edge input[E];
    Edge output[V-1];// our MST
    //1 take input
    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i]=Edge(s,d,w);
    }
    
    
    
    
    //2 sort the array
    sort(input,input+E,wayToSort);
    
    int parent[V];
    for(int i=0;i<V;i++)
        parent[i]=i;    // initilalise the parent array
    int count=0;   // EDGES ENTERED MST
    
    
    // V vertices so V-1 edges in MST
    for(int i=0;i<E,count<V-1;i++){
        // for every edge ---v1 and v2  cheak if p1!=p2   ---if p1=p2 skip edge
        int v1=input[i].source;
        int v2=input[i].destination;
        int p1=getParent(parent,v1);
        int p2=getParent(parent,v2);
        if(p1==p2)
            continue;
        if(p1!=p2){
            output[count]=input[i];
            count++;
            parent[p1]=p2;
            
        }
        
        
        
    }
    
    
    for(int i=0;i<V-1;i++){
        if(output[i].source<=output[i].destination){
            cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
        }else{
            cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
            
        }
    }
    
    
    
    
    return 0;
}
