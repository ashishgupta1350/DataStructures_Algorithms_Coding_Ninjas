#include<iostream>
#include<vector>
using namespace std;
#include"BTNodeClass.cpp"
#include<queue>

void printTreeProper(BinaryTreeNode<int>* root)
{

    if(root==NULL) return;
    cout<<root->data<<":";
    if(root->left)
        cout<<"L"<<root->left->data<<" ";
    if(root->right)
    {
        cout<<"R"<<root->right->data;

    }
    cout<<endl;
    printTreeProper(root->left);
    printTreeProper(root->right);
    return;

}
BinaryTreeNode<int>* takeInputLevelWise()
{
    BinaryTreeNode<int>* root;
    BinaryTreeNode<int>* leftChildNode;
    BinaryTreeNode<int>* rightChildNode;
    int data;
    cout<<"Enter Root Data: "<<endl;cin>>data;
    if(data==-1) return NULL;

    root=new BinaryTreeNode<int> (data);

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(q.size()!=0)
    {
        int child_left=-1,child_right=-1;
        BinaryTreeNode<int>*temp=q.front();
        q.pop();
        cout<<"Enter left child of "<<temp->data<<endl;
        cin>>child_left;
        cout<<"Enter right child of "<<temp->data<<endl;
        cin>>child_right;
        if(child_left!=-1)
        {
            leftChildNode=new BinaryTreeNode<int> (child_left);
            temp->left=leftChildNode;
            q.push(leftChildNode);

        }
        if(child_right!=-1)
        {
            rightChildNode=new BinaryTreeNode<int> (child_right);
            temp->right=rightChildNode;
            q.push(rightChildNode);

        }
    }
    return root;

}

void printAtLevelK(BinaryTreeNode<int>*root,int k)
{
    if(root==NULL) return;
    if(k==0) {cout<<root->data<<endl;
    return;}
    else{
        printAtLevelK(root->left,k-1);
        printAtLevelK(root->right,k-1);
        return;
    }

}
class Pair{
public:

  bool isThere;
  int depth;

  Pair()
  {
      isThere=false;
      depth=0;
  }
   Pair(bool a,int d)
  {
      isThere=a;
      depth=d;
  }

};
Pair isNodeThereAndDepth(BinaryTreeNode<int>*root,int data)
{
    if(root==NULL){
       Pair p;
       return p;
    }

    if(root->data==data)
    {
        Pair p(true,1);return p;

    }
    Pair p1,p2;
    p1=isNodeThereAndDepth(root->left,data);
    p2=isNodeThereAndDepth(root->right,data);

    if(p1.isThere){
        p1.depth+=1;
        return p1;
    }
    else if(p2.isThere) {
        p2.depth+=1;
        return p2;}
    else{
        Pair p;
        return p;
    }

}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
    cout<<" i come here"<<endl;
    if(root==NULL) return;
    cout<<"Root's data is : "<<root->data<<" value of k is : "<<k<<" and value of node to search is "<<node<<endl;
    if(root->data==node)
    {
        printAtLevelK(root,k);
    }
    Pair p1,p2;

    p1=isNodeThereAndDepth(root->left,node);
    if(p1.isThere)
    {
        cout<<" p1 depth is : "<<p1.depth<<endl;
        if(p1.depth==k) cout<<root->data<<endl;
        else if(p1.depth<k)
        {
            printAtLevelK(root->right,k-p1.depth-1);///check if it will really print at depth - k or any other higher or lower level

        }
            nodesAtDistanceK(root->left,node,k);
    }
    p2=isNodeThereAndDepth(root->right,node);
    if(p2.isThere)
    {
        if(p2.depth==k) cout<<root->data<<endl;
        else if(p2.depth<k)
        {
            printAtLevelK(root->left,p2.depth-k);/class BST:
    def __init__(self):
        self.root=None

    def Insert(self,data):
        newNode=treeNode(data)
        if(self.root==None):
            self.root=newNode
            return

        elif self.root.data>data:
            self.Insert(data)
//check if it will really print ar depth - k or any other higher or lower level

        }
            nodesAtDistanceK(root->right,node,k);
    }
    return;
}
///1 2 3 4 5 -1 -1 6 7 -1 -1 -1 -1 -1 -1class BST:
    def __init__(self):
        self.root=None

    def Insert(self,data):
        newNode=treeNode(data)
        if(self.root==None):
            self.root=newNode
            return

        elif self.root.data>data:
            self.Insert(data)

///5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
int main()
{
    BinaryTreeNode<int>*root;
    root=takeInputLevelWise();
    cout<<endl<<endl;
    printTreeProper(root);
    cout<<endl;
    int k=2;
    int level=3;
    cout<<"I am here"<<endl;
    if(! root) cout<<"root is null"<<endl;
    printAtLevelK(root,2);
    Pair p=isNodeThereAndDepth(root,2);
    cout<<p.isThere<<endl;
    if(p.isThere) cout<<p.depth<<endl;
    cout<<endl;
    cout<<endl;
    nodesAtDistanceK(root,2,2);

    return 0;



}

