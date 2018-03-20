class StackUsingArrays{
	int *data;
	int nextIndex,capacity;
public:
    StackUsingArrays(int n)
    {
        data=new int[n];
        nextIndex=0;
        capacity=n;
    }
    void push(int n)
    {
        if(nextIndex==capacity) {cout<<"Stack is FULL"<<endl; return ;}

        data[nextIndex++]=n;

    }
	void pop(){
	    if(nextIndex>0)
        nextIndex--;
	}
	int top() const
	{
	    if(nextIndex>0) return data[nextIndex-1];
	    else return -2131233;
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
