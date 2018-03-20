
template<typename T>
class Queue{

  T *data;
  int firstIndex;
  int nextIndex;
  int Size;
  int totalSize;
public:
    Queue()
    {
       // if(n==0) return;
        this->data=new T[5];
        firstIndex=-1;
        nextIndex=0;Size=0;totalSize=5;


    }
    void enqueue(T n)
    {
        ///cout<<"In enqueue"<<endl;
        ///cout<<" First index: "<<firstIndex<<" and last index is : "<<nextIndex<<"and total size is : "<<totalSize<<endl;
       /// nextIndex%=totalSize;
        if(firstIndex==-1) {

            firstIndex++;nextIndex++;
            data[firstIndex]=n;
            nextIndex%=totalSize;
            Size=1;
            return;

        }
        else if(firstIndex==nextIndex){
                cout<<"Increasing size"<<endl;
            T *newData=new T[2*totalSize];
            int j=0;
            for(int i=firstIndex;i<totalSize;i++)
            {
                newData[j]=data[i];
                j++;

            }
            for(int i=0;i<nextIndex;i++)
            {
                newData[j]=data[i];
                j++;
            }
            Size++;
            newData[j++]=n;
            totalSize*=2;
            firstIndex=0;
            nextIndex=j;
            nextIndex%=totalSize;
            delete[] data;
            data=newData;
            return;
        }
        Size++;
        data[nextIndex++]=n; nextIndex%=totalSize;
        return;

    }
    int size() const{return Size;}
    void dequeue()
    {
        if(Size==0)return;
        firstIndex++;Size--;
        firstIndex%=totalSize;


    }
    T Front()const
    {
        if(Size==0) {cout<<"Empty"<<endl;return 0;}
        else return data[firstIndex];


    }
    bool isEmpty() const
    {

        return Size==0;
    }
};
