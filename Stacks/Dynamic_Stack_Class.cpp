template<typename T >

class StackUsingArrays{
	T *data;
	int nextIndex,capacity;
public:
    StackUsingArrays()
    {
        data=new T[5];
        nextIndex=0;
        capacity=5;
    }
    void push(T n)
    {
        if(nextIndex<capacity)
            data[nextIndex++]=n;
        else{

            T *newData=new T[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newData[i]=data[i];

            }
            newData[nextIndex++]=n;
            capacity*=2;
            delete[]data;
            data=newData;
        }
    }
	void pop(){
	    if(nextIndex==capacity+1&&nextIndex!=6)
        {
            T *newData=new T[capacity/2];
            for(int i=0;i<capacity;i++)
            {
                newData[i]=data[i];

            }
            delete[]data;
            capacity/=2;
            nextIndex--;
            data=newData;

        }

	    else if(nextIndex>0)
        nextIndex--;
	}
	T top() const
	{
	    if(nextIndex>0) return data[nextIndex-1];
	    else{

            cout<<"Stack is empty"<<endl;
            return 0;
	    }
	}
	int size() const{return nextIndex;}
	bool isempty() const{
        return (nextIndex==0)? true: false;

	}
    ~StackUsingArrays()
    {
        delete[]data;
    }
};

