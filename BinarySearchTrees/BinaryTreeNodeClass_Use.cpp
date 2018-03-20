#include<iostream>
#include<vector>
using namespace std;
#include"BTNodeClass.cpp"
#include<queue>
void print(int *a,int s,int e)
{
    for(int i=s;i<=e;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void printTree(BinaryTreeNode<int>* root)
{
    if(root==NULL) return ;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);

}
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
BinaryTreeNode<int>* takeInput()
{
    int data;
    cout<<"Enter Data "<<endl;
    cin>>data;
    if(data==-1) return NULL;

    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(data);

    root->left=takeInput();
    root->right=takeInput();
    return root;


}/// simple input 1 2 -1 4 -1 -1 3 5 -1 -1 6 -1 -1
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

void InOrder(BinaryTreeNode<int>*root)
{
    if(root==NULL) return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
    return;
}
void postOrder(BinaryTreeNode<int>*root)
{
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    return;
}
void preOrder(BinaryTreeNode<int>*root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

/// get Tree works fine:)
BinaryTreeNode<int>* getTree(int *pre,int *in,int preS,int preE,int inS,int inE)
{
    ///int size=ei_pre-si_pre+1;
      if(inS>inE) return NULL;

    int rootIndex=-1;
    for(int i=inS;i<=inE;i++)
    {
        if(in[i]==pre[preS])
        {
            rootIndex=i;
            break;
        }

    }
    int rootData=pre[preS];
    int lPreS=preS+1;
    int lInS=inS;
    int lInE=rootIndex-1;
    int lPreE=lInE-lInS+lPreS;
    int rPreS=lPreE+1;
    int rPreE=preE;
    int rInS=rootIndex+1;
    int rInE=inE;

    BinaryTreeNode<int>* root=new BinaryTreeNode<int> (rootData);
    root->left=getTree(pre,in,lPreS,lPreE,lInS,lInE);

    root->right=getTree(pre,in,rPreS,rPreE,rInS,rInE);

     return root;


}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    int s1,e1,s2,e2;
    s1=0;s2=0;e1=preLength-1;e2=inLength-1;
   /// cout<<"I am in First function: "<<endl;
    return getTree(preorder,inorder,s1,e1,s2,e2);
}


BinaryTreeNode<int>* getTree1(int *post,int *in,int postS,int postE,int inS,int inE)
{
    if(inS>inE) return NULL;

    int rootIndex=-1;
    for(int i=inS;i<=inE;i++)
    {
        if(in[i]==post[postE])
        {
            rootIndex=i;
            break;
        }

    }
    int rootData=post[postE];

    int lInS=inS;
    int lInE=rootIndex-1;
    int lPostS=postS;
    int lPostE=lInE-lInS+lPostS;
    int rInS=rootIndex+1;
    int rInE=inE;
    int rPostS=lPostE+1;
    int rPostE=postE-1;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int> (rootData);
    root->left=getTree(post,in,lPostS,lPostE,lInS,lInE);

    root->right=getTree(post,in,rPostS,rPostE,rInS,rInE);

     return root;


}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    int len=inLength-1;
    return getTree1(postorder,inorder,0,len,0,len);

}

int height(BinaryTreeNode<int>*root)
{
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));

}

int diameter(BinaryTreeNode<int>* root)
{
    if(root==NULL) return 0;
    int h1=height(root->left);
    int h2=height(root->right);
   /// cout<<"H1 and H2 are : "<<h1<< " and "<<h2<<endl;
    int d1=diameter(root->left);
    int d2=diameter(root->right);
    return max(max(h1+h2,d1),d2);

}

///better approach for diameter 13/8/17

class Pair{
public:
    int height;
    int diameter;
    Pair()
    {
        height=diameter=0;

    }
    Pair(int h,int d)
    {
        height=h;
        diameter=d;

    }
};

Pair heightAndDiameter(BinaryTreeNode<int>*root)
{
    Pair HandD;
    if(root==NULL) return HandD;
    Pair p1=heightAndDiameter(root->left);
    Pair p2=heightAndDiameter(root->right);

    int height_leftTree=p1.height;
    int height_rightTree=p2.height;
    int diameter_leftTree=p1.diameter;
    int diameter_rightTree=p2.diameter;

    int height=1+max(height_leftTree,height_rightTree);
    int diameter=max(max(height_leftTree+height_rightTree,diameter_leftTree),diameter_rightTree);

    Pair P(height,diameter);
    return P;

}
int diameterAdvanced(BinaryTreeNode<int>*root)
{
    return heightAndDiameter(root).diameter;

}


vector<int> findPath(BinaryTreeNode<int>* root,int x)
{
    if(! root) {
        vector<int> v;
        return v;
    }
    if(root->data==x)
    {

        vector<int> v;
        v.push_back(x);
        return v;

    }
    vector<int> vLeft=findPath(root->left,x);
    if(vLeft.size())
    {
        vLeft.push_back(root->data);
        return vLeft;

    }
    vector<int> vRight=findPath(root->right,x);
    if(vRight.size())
    {

        vRight.push_back(root->data);
        return vRight;
    }
    else return vRight;
}

int main()
{
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>*node1=new BinaryTreeNode<int>(20);
    BinaryTreeNode<int>*node2=new BinaryTreeNode<int>(30);
    root->left=node1;
    root->right=node2;
    node2=new BinaryTreeNode<int>(40);
    root->left->right=node2;
   /* cout<<"The class print function: "<<endl;
    root->printTree();
    cout<<endl<<"Other one : "<<endl;

printTree(root);*/
    delete root;
    /*cout<<endl<<"New Tree"<<endl;
    root=takeInput();*/
   /* cout<<"Tree Level Wise: "<<endl;
   root= takeInputLevelWise();
   cout<<endl;
   InOrder(root);
   cout<<endl;*/

   /*int a1[10000];
   int a2[10000];
   int size1,size2;
   int n;
   cin>>n;
   size1=size2=n;
   for(int i=0;i<n;i++)
   {

       cin>>a1[i];
   }
    for(int i=0;i<n;i++)
   {
       cin>>a2[i];
   }

   root=buildTree(a1,size1,a2,size2);
    printTreeProper(root);
    */
    root=takeInputLevelWise();
    printTreeProper(root);
   /// postOrder(root);cout<<endl;
    ///preOrder(root);
    cout<<"The diameter is : ";
    cout<<diameterAdvanced(root)<<endl;

    vector<int> v;
    cout<<"I am now to find path "<<endl;
    cout<<"enter integer : ";
    int n;
    cin>>n;
    v=findPath(root,n);
    ///1 2 3 4 5 -1 7 -1 -1 6 -1 -1 -1 -1 -1
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<< " ";

    }
    cout<<endl<<"End of path"<<endl;
    return 0;
}

