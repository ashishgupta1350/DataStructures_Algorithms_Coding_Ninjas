class DynamicArray{
  public:
      int*data;int nextIndex;int Size;

  DynamicArray()
  {
      data=new int [5];
      nextIndex=0;
      Size=5;
  }
  void add(int x)
  {
      if(nextIndex==Size)
      {
          int *data1=new int[2*Size];
          for(int i=0;i<Size;i++)
          {
              data1[i]=data[i];
          }
          data1[nextIndex++]=x;
          delete[]data;
          data=data1;
      }
      else{
        data[nextIndex++]=x;
      }
  }
          void print()
      {
          for(int i=0;i<nextIndex;i++)
          {
              cout<<data[i]<< " ";
          }
          cout<<endl;
      }
    void add(int i,int element)
    {
        if(i<nextIndex)
        {
            data[i]=element;

        }
        else if(i==nextIndex)
        {

            data[nextIndex++]=element;
        }
        else{
            return;
        }

    }

    DynamicArray (DynamicArray const&d){

        this->data=new int[d.Size];
        for(int i=0;i<d.nextIndex;i++)
        {
            this->data[i]=d.data[i];
        }
        this->nextIndex=d.nextIndex;
        this->Size=d.Size;

    }
    void operator=(DynamicArray const& d)
    {
         this->data=new int[d.Size];
        for(int i=0;i<d.nextIndex;i++)
        {
            this->data[i]=d.data[i];
        }
        this->nextIndex=d.nextIndex;
        this->Size=d.Size;
    }

};
