#include<vector>
#include<cmath>
#include<algorithm>

class PriorityQueue{
    vector<int> pq;
public:
    ///constructor is not needed
    int getSize()
    {
        return pq.size();
    }
    bool isEmpty()
    {
        return pq.size()==0;
    }
    int getMin()
    {
        if(isEmpty()) return 0;
        else return pq[0];

    }
    void Insert(int value)
    {
        pq.push_back(value);
        int index=pq.size()-1;
        while(index>0)
        {
            if((index-1)/2>=0&&pq[(index-1)/2]>value)
            {
                swap(pq[index],pq[(index-1)/2]);
                index=(index-1)/2;

            }
            else break;
        }
    }
    void Remove()
    {
        //int vectorSize=v.size();
        if(pq.size()==0) return;
        cout<<"here 1"<<endl;
        int index=pq.size()-1;
        swap(pq[0],pq[index]);
        pq.pop_back();
        index=0;
        while(index<pq.size())
        {
            if(2*index+1>=pq.size()) return ;
            if(2*index+1<pq.size()&&(2*index+2)>=pq.size())
            {
                if(pq[2*index+1]<pq[index])
                {
                    swap(pq[2*index+1],pq[index]);
                    index=2*index+1;
                    break;
                }
                else break;

            }
            else{
                if(pq[2*index+1]<pq[2*index+2])
                {
                    if(pq[2*index+1]<pq[index]){
                        swap(pq[2*index+1],pq[index]);
                    }
                     index=2*index+1;
                }
                else{
                    if(pq[2*index+2]<pq[index]){
                        swap(pq[2*index+2],pq[index]);


                    }
                      index=2*index+2;
                }

            }
        }
    }

};
