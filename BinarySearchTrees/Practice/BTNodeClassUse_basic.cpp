#include<iostream>
#include"BTNode.h"
using namespace std;
#include<vector>
#include<climits>
class Triple{
  public:

  int Max;
  int Min;
  bool isBST;
  Triple()
  {
      Max=INT_MIN;
      Min=INT_MAX;
      isBST=true;
  }

};
Triple isBSTMaxMin(BinaryTreeNode<int>*);

int main()
{

    return 0;
}

Triple isBSTMaxMin(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        Triple p;
        return p;
    }
    Triple tLeft,tRight;
    tLeft=isBSTMaxMin(root->left);
    tRight=isBSTMaxMin(root->right);
    bool isTrue;
    if(tLeft.Max<root->data&&tRight.Min>=root->data)
    {
        isTrue=true;

    }
    else isTrue=false;

    if(isTrue&&tLeft.isBST&&tRight.isBST)
    {

        Triple t;
        t.isBST=true;
        t.Min=min(root->data,min(tLeft.Min,tRight.Min));
        t.Max=max(root->data,max(tLeft.Max,tRight.Max));
        return t;

    }
    else
    {
        Triple t;
        t.isBST=false;
        t.Min=min(root->data,min(tLeft.Min,tRight.Min));
        t.Max=max(root->data,max(tLeft.Max,tRight.Max));
        return t;

    }



}
bool isBST(BinaryTreeNode<int>*root)
{
    return isBSTMaxMin(root).isBST;
}

bool Search(BinaryTreeNode<int>*root,int x)
{
    if(root==NULL) return false;
    if(root->data==x) return true;
    if(x<root->data)
    {
        return Search(root->left,x);

    }
    else
    {
        return Search(root->right,x);

    }
}

vector<int> findPath(BinaryTreeNode<int>*root,int x){
    if(Search(root,x)==false||root==NULL)
    {
        vector<int> v;
        return v;
    }
    if(root->data==x)
    {
        vector<int> v;
        v.push_back(root->data);
        return v;

    }
    vector<int> v1,v2;
    if(x<root->data)
    {
        v1=findPath(root->left,x);
        if(v1.size())
        {
            v1.push_back(root->data);


        }
        return v1;
    }
    else{
        v2=findPath(root->right,x);
        if(v2.size())
        {
            v2.push_back(root->data);


        }
        return v2;


    }

}
