#include<iostream>
#include"TreeNode.h"
using namespace std;
#include<queue>
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)


TreeNode<int>* takeInput()
{
    int data;
    cout<<"Enter data : "<<endl;
    cin>>data;
    TreeNode<int>* root=new TreeNode<int> (data);
    int n;
    cout<<"enter number of children of : "<<data<<" : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        TreeNode<int>*child=takeInput();
        root->children.push_back(child);


    }
    return root;
}

void levelOrderPrint(TreeNode<int>* root)
{

    if(root==NULL) return ;
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++)
    {
        if(i!=root->children.size()-1)
        cout<<root->children[i]->data<< ",";
        else{

            cout<<root->children[i]->data;
        }
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
        levelOrderPrint(root->children[i]);
}

void printTree(TreeNode<int>* root){

    if(root==NULL) return;

    cout<<root->data<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        printTree(root->children[i]);
    }

}

TreeNode<int>* takeInputLevelWise()
{
  int rootData;
   // cout<<"Enter root data : "<<endl;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int> (rootData);
    queue <TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>*temp=q.front();
        q.pop();
        int n;
       // cout<<"Enter number of children of "<<temp->data<<" : ";
        cin>>n;
        REP(i,n){
            int data;
           // cout<<"Enter data : ";
            cin>>data;
            TreeNode<int>* child=new TreeNode<int>(data);
            q.push(child);
            temp->children.push_back(child);
        }

    }
    return root;

}

void printLevelWise(TreeNode<int>* root)
{
    if(root==NULL) return ;
    queue <TreeNode<int>*> q;
    int sum=0;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>*temp=q.front();
        q.pop();
        ///cout<<temp->data<<":";
        sum+=temp->data;
        REP(i,temp->children.size())
        {

            q.push(temp->children[i]);
        }
    ///cout<<endl;
    }

}
int main()
{
    /*TreeNode<int>*root=new TreeNode<int>(10);
    TreeNode<int> *n1=new TreeNode<int>(20);
    TreeNode<int>*n2=new TreeNode<int>(30);
    root->children.push_back(n1);
    root->children.push_back(n2);
        ///cout<<root->data<<" " <<root->children[0]->data<<" "<<root->children[1]->data<<" "<<endl;
    printTree(root);
    levelOrderPrint(root);

    cout<<endl<<endl;
*/
    cout<<"Want to input a tree?  : ";
    char ch;cin>>ch;int n;
    if(ch=='y'||ch=='Y')
    {
        cin>>n;
        TreeNode<int >*root=takeInputLevelWise();
        printLevelWise(root);


    }
    return 0;

}
