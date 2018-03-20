template<typename T>
class Node{
public:
    T data;
    Node<T>*next;
    Node(T d)
    {
        data=d;
        next=NULL;

    }

};

template<typename T>
class StackUsingLL{

private:
    Node<T>*head;
    int Size;
public:
    StackUsingLL()
    {
        head=NULL;
        Size=0;

    }
    int getSize()
    {
        return this->Size;
    }
    bool isempty(){
        return Size==0;
    }

    T top()
    {
        if(head==NULL){
                cout<<"Stack is empty"<<endl;
            return 0;
        }
        else{
            return head->data;

        }

    }
    void push(T data)
    {
        Size++;Node<T>*newNode=new Node<T>(data);
        if(head==NULL){

            head=newNode;

        }
        else{
            newNode->next=head;
            head=newNode;
        }
        return;

    }
    void pop()
    {
        if(head==NULL) return;
        else{
            Node<T>*temp=head;
            head=head->next;
            delete temp;
            Size--;

        }


    }
};
