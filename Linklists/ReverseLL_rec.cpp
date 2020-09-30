// Reverse Linked List Recursively
#include <iostream>
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
node *reverse_linked_list_rec(node *head)
{
    //write your recursive code here
    node *temp = head;

    if(head->next == NULL){
        return head;
    }
    
    node *smallAns = reverse_linked_list_rec(temp->next);
    
    temp->next = smallAns;
    
    return temp;
}
int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		head = reverse_linked_list_rec(head);
		print(head);
	}

	return 0;
}
