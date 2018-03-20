#include"BTNodeClass.cpp"

class BST{
public:
    BinaryTreeNode<int>* root;
    int numberOfNodes;
public:
    BST()
    {
        root=NULL;
        numberOfNodes=0;
    }
private:

    bool hasDataHelper(int data,BinaryTreeNode<int>*node){
        if(node==NULL) return false;
        if(node->data==data) return true;
        else{

            ///since this is a BST
            if(data<node->data)
            {
                return hasDataHelper(data,node->left);
            }
            else return hasDataHelper(data,node->right);
        }


    }
public:

    bool hasData(int data){
        return hasDataHelper(data,root);
    }

private:
    void insertHelper(int data,BinaryTreeNode<int>*&node){
        ///cout<<"In insertHelper"<<endl;
        if(node==NULL)
        {
            ///cout<<"I am here"<<endl;
            node=new BinaryTreeNode<int>(data);

            return;
        }
        if(data<node->data&&node->left==NULL){
            ///cout<<"I am in root->left"<<endl<<" and root->Data== "<<node->data<<endl;
            BinaryTreeNode<int>*n=new BinaryTreeNode<int>(data);
            node->left=n;
            return;
        }
        else if(data>=node->data&&node->right==NULL){

            BinaryTreeNode<int>*n=new BinaryTreeNode<int>(data);
            node->right=n;
            return;
        }
        else{
            if(data<node->data)
            {
                insertHelper(data,node->left); return;
            }
            else{
                insertHelper(data,node->right); return;
            }
        }

    }
public:

    void Insert(int data){
        ///if(!root) cout<<"Root is NULL"<<endl;
        insertHelper(data,root);
        ///cout<<root->data<<" : is roots data after insertion "<<endl;

    }
private:
   void printTreeProper(BinaryTreeNode<int>* root)
{

    if(root==NULL) return;
    cout<<root->data<<":";
    if(root->left)
        cout<<"L"<<root->left->data<<",";
    if(root->right)
    {
        cout<<"R"<<root->right->data;

    }
    cout<<endl;
    printTreeProper(root->left);
    printTreeProper(root->right);
    return;


}
public:

    void print()
    {
        printTreeProper(root);

    }
private:
    BinaryTreeNode<int>* minimum(BinaryTreeNode<int>*root)
    {
       if(!root) return root;

        BinaryTreeNode<int>*Lmin=minimum(root->left);
        BinaryTreeNode<int>*Rmin=minimum(root->right);
        if(Lmin==NULL&&Rmin==NULL) return root;
        else if(Lmin==NULL){
            if(root->data<Rmin->data) return root;
            else return Rmin;
        }
        else if(Rmin==NULL){
            if(root->data<Lmin->data) return root;
            else return Lmin;
        }
        if(root->data<Lmin->data&&root->data<Rmin->data) return root;
        else if(Lmin->data<Rmin->data){return Lmin;}
        else return Rmin;


    }
  /*  BinaryTreeNode<int>* deleteDataHelper(int data,BinaryTreeNode<int>*root){
        if(root==NULL) return root;
        if(root->data==data)
        {
            if(!(root->left||root->right))
            {
                return NULL;

            }
            else if(!root->left&&root->right)
            {
                return root->right;

            }
            else if(!root->right&&root->left)
            {
                return root->left;
            }
            else{
                BinaryTreeNode<int>*node=minimum(root->right);
                root->data=node->data;
                node=deleteDataHelper(node->data,node);

            }
            return root;
        }
        else{
            if(data<root->data)
            {
               root->left= deleteDataHelper(data,root->left);
            }
            else{
                root->right=deleteDataHelper(data,root->right);
            }
            return root;
        }

    }*/
    public:
    void deleteData(int data)
    {
        root=deleteDataHelper(root,data);

    }
    BinaryTreeNode<int>*deleteDataHelper(BinaryTreeNode<int>*root,int value){
        if(root==NULL) return root;
        if(root->data<value)
        {
            deleteDataHelper(root->left,value);
        }
        else if(root->data>value)
        {
            deleteDataHelper(root->right,value);
        }
        else{
            if(root->left==NULL&&root->right==NULL)
            {
                delete root;
                return NULL;

            }
            else if(root->left==NULL)
            {
                BinaryTreeNode<int>*temp=root->right;
                root->right=NULL;
                delete root;
                return temp;

            }
            else if(root->right==NULL)
            {
                BinaryTreeNode<int>*temp=root->left;
                root->left=NULL;
                delete root;
                return temp;

            }
            else {
                BinaryTreeNode<int>*temp=root->right;
                while(temp!=NULL&&temp->left!=NULL)
                {
                    temp=temp->left;
                }
                root->data=temp->data;
                root->right=deleteDataHelper(root->right,value);
                return root;

            }


        }


    }
};
