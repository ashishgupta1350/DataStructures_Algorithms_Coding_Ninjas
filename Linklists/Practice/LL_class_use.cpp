#include<iostream>
using namespace std;
#include"LL_Node.cpp"
int length_ll(Node*head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;

    }
    return count;
}

void print(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;

    }
    cout<<endl;
    return;
}
Node* takeInput()
{
    int data;
    cin>>data; Node*head=NULL;Node*tail=NULL;
    while(data!=-1)
    {
        Node*n=new Node(data);
        if(head==NULL)
        {
            head=tail=n;
        }
        else{
            tail->next=n;
            tail=n;
        }
        cin>>data;
    }

    return head;
}
Node* InsertAtI(Node* head,int data,int index)
{
    Node*n=new Node(data);Node*temp2=NULL;
        if(head==NULL)
        {
            if(index==0) head=n;return head;
        }
        else if(length_ll(head)<index) return head;
        else{
            Node*temp=head;
            for(int i=0;i<index-1;i++)
            {
                temp=temp->next;

            }
            if(temp!=NULL) {temp2=temp->next;}
            temp->next=n;
            n->next=temp2;

        }

    return head;
}

int main()
{
    Node*head;
    head=takeInput();
    print(head);
    head=InsertAtI(head,99,4);
    print(head);
    return 0;
}
