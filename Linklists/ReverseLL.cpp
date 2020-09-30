// Reverse LL (Iterative)

#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
using namespace std;
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* rev_linkedlist_itr(node* head)
{
    //write your iterative code here
    node *prev = NULL;
    node *curr = head;
    node *n;
    
    while(curr != NULL){
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    
    return prev;
}
int main(){
    node* head=takeinput();
    head=rev_linkedlist_itr(head);
    print(head);
    return 0;
}



