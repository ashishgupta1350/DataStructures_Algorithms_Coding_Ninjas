

class Node{
    public:
    int data;
    Node* next;
    static int size1;

    Node(int data){
        size1++;
        this->data=data;
        this->next=NULL;
    }

};
int Node::size1=0;
