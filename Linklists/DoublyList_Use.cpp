#include<iostream>
using namespace std;
#include"Class_DoublyLL.cpp"

Node* takeInput()
{
    int data;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=-1)
    {
        Node*n=new Node(data);
        if(head==NULL)
        {
            head=n;tail=n;

        }
        else{
            tail->next=n;
            n->prev=tail;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;

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
Node* reverse_LL(Node*head){
    while(head->next!=NULL) {
        head=head->next;
    }
    while(head!=NULL){

        cout<<head->data<<" ";

        head=head->prev;

    }
    return head;
}
int main()
{
    Node*head=takeInput();
    print(head);
    reverse_LL(head);
    return 0;
}
