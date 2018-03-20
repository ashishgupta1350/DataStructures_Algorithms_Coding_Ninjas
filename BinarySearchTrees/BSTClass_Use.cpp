#include<iostream>
using namespace std;
#include"BSTClass.h"
#include<limits>
class Triple
{
  public:
    bool isBST;
    int Maximum;
    int Minimum;
    Triple()
    {
        isBST=true;
        Maximum=INT_MIN;
        Minimum=INT_MAX;

    }

};
Triple isBSTmaxMin(BinaryTreeNode<int>*root)
{
    if(root==NULL){
        Triple t;
        return t;
    }
    Triple t1,t2;
    t1=isBSTmaxMin(root->left);
    t2=isBSTmaxMin(root->right);
    if(!(t1.isBST&&t2.isBST))
    {
        Triple t;
        t.isBST=false;
        t.Maximum=max(root->data,max(t1.Maximum,t2.Maximum));
        t.Minimum=min(root->data,min(t1.Minimum,t2.Minimum));
        return t;
    }
    else{
        Triple t;
        t.Maximum=max(root->data,max(t1.Maximum,t2.Maximum));
        t.Minimum=min(root->data,min(t1.Minimum,t2.Minimum));
        if(root->data>t1.Maximum&&root->data<=t2.Minimum)
        {
            t.isBST=true;
        }
        else t.isBST=false;
        return t;
    }

}
bool isBST(BinaryTreeNode<int>*root)
{
    return isBSTmaxMin(root).isBST;

}

void makeBSThelper( BST &b, int *a,int s,int e)
{
    if(s>e)
    {
        return;
    }

    int mid=(s+e)/2;
    b.Insert(a[mid]);
    makeBSThelper(b,a,s,mid-1);
    makeBSThelper(b,a,mid+1,e);
    return ;

}

BST makeBST_sortedArray(int *a,int n){
    BST b;
    makeBSThelper(b,a,0,n-1);
    return b;
}

int main()
{

    BST b;
    b.Insert(10);
    b.Insert(5);
    b.Insert(15);
    b.Insert(3);
    b.Insert(20);
    cout<<"Check if tree has 10 "<<endl;
    (b.hasData(10))? cout<<"Has 10 as data"<<endl:cout<<"Does not have 10 "<<endl;
    b.deleteData(10);
    cout<<"removed 10"<<endl;
    (b.hasData(10))? cout<<"Has 10 as data"<<endl:cout<<"Does not have 10 "<<endl;
    cout<<"printing tree"<<endl;
    b.print();
    cout<<"Is it BST: "<<isBST(b.root)<<endl;
    cout<<endl;
    cout<<"Making a bst out of sorted array"<<endl;
    int *a=new int[10];
    for(int i=0;i<10;i++)
    {
        a[i]=i;

    }
   BST bst_sortedArray= makeBST_sortedArray(a,10);
   bst_sortedArray.print();


    return 0;
}
