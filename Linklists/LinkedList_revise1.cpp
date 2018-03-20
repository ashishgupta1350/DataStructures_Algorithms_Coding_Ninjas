#include<iostream>
using namespace std;
#include"Node.cpp"

class Pair{
public:
    Node*head;
    Node*tail;
    Pair()
    {
        head=NULL;
        tail=NULL;
    }
};

Pair reverse_ll(Node*head)
{
    if(head==NULL||head->next==NULL)
    {
        Pair Ans;
        Ans.head=head;
        Ans.tail=head;
        return Ans;
    }
    Pair smallAns=reverse_ll(head->next);
    smallAns.tail->next=head;
    head->next=NULL;
    smallAns.tail=smallAns.tail->next;
    return smallAns;
}

Node* reverse_LL(Node*head){
    Pair Ans;
    Ans=reverse_ll(head);
    return Ans.head;
}

Node* takeInput()
{
    int data;
    cin>>data;
    Node* tail;
    Node*head=NULL;
    while(data!=-1)
    {
        Node*newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void Insert(Node* &head,int i,int data)
{
    Node*newNode=new Node(data);
    int count=0;
    Node*temp=head;
    while(count<i-1&&temp->next!=NULL)
    {
        temp=temp->next;count++;

    }
    if(i==0){
        newNode->next=head;
        head=newNode;



    }
    newNode->next=temp->next;
    temp->next=newNode;


}

void print(Node* head){
    while(head!=NULL)
    {
        cout<<head->data;
        if(head->next!=NULL)
        cout<<"->";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    Node*head=takeInput();
    print(head);
    head=reverse_LL(head);
    print(head);
    return 0;
}
