#include<iostream>
using namespace std;
#include"Class_LL.cpp"

Node* takeInput(){
    int data;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=-1){
        Node*n=new Node(data);
        if(head==NULL)
        {
            head=n;
            tail=n;
        }
        else{

            tail->next=n;
            tail=tail->next;

        }
        cin>>data;
    }
    return head;
}

void print(Node*head){
    Node* temp=head;
    while(temp!=NULL){

        cout<<temp->data<<" " ;
        temp=temp->next;

    }
    cout<<endl;

}
int main()
{
   Node*head=takeInput();
   print(head);
    ///dynamic node
   /* Node* n1=new Node(10);
    Node*n2=new Node(20);
    Node*n3=new Node(3);
    Node*n4=new Node(40);
    Node*n5=new Node(50);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    Node*head;
    head=n1;
    print(head);*/


    return 0;



}
