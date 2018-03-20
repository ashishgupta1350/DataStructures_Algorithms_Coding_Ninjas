#include"BTNodeClass.cpp"
template<typename T>
class HashMap{
private:
    BinaryTreeNode<T>*root;
    int Size;

public:
    HashMap()
    {

        root=NULL;Size=0;
    }

    void printHelper(BinaryTreeNode<T>*root)
    {
        if(root==NULL) return;
        cout<<root->Key<<":";
        if(root->left) cout<<"L:"<<root->left->Key<<",";
        if(root->right) cout<<"R:"<<root->right->Key;
        cout<<endl;
        printHelper(root->left);
        printHelper(root->right);
        return;
    }
    void printTree()
    {

        printHelper(root);
        return;
    }
private:


    bool searchHelper(BinaryTreeNode<T>*root,int Key)
    {
        ///cout<<"In search helper"<<endl;
        if(root==NULL) return false;
        if(root->Key==Key) return true;
        if(Key<root->Key){
            return searchHelper(root->left,Key);
        }
        else {
            return searchHelper(root->right,Key);
        }
        return false;///No need
    }
public:
    bool Search(int key)
    {
       /// cout<<"In search"<<endl;
        return searchHelper(root,key);
    }

    private:
    BinaryTreeNode<T>* insertHelper(int Key,T data,BinaryTreeNode<T>*node){
        if(node==NULL)
        {
            node=new BinaryTreeNode<T>(Key,data);

            return node;
        }
        if(Key<node->Key&&node->left==NULL){
            BinaryTreeNode<T>*n=new BinaryTreeNode<T>(Key,data);
            node->left=n;
            return node;
        }
        else if(Key>=node->Key&&node->right==NULL){

            BinaryTreeNode<T>*n=new BinaryTreeNode<T>(Key,data);
            node->right=n;
            return node;
        }
        else{
            if(Key<node->Key)
            {
               node->left= insertHelper(Key,data,node->left); return node;
            }
            else{
                node->right= insertHelper(Key,data,node->right); return node;
            }
        }
    }
public:

    void Insert(int Key,T data){
        bool isKeyPresent=Search(Key);
        if(isKeyPresent){
            cout<<"The Key already Exists"<<endl;
            return;
        }
        else
        root=insertHelper(Key,data,root);
        return;
    }

    /*BinaryTreeNode<int>* deleteDataHelper(int Key,BinaryTreeNode<int>*root){
        if(root==NULL) return root;
        if(root->Key==Key)
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
                root->Key=node->Key;
                node=deleteDataHelper(node->Key,node);

            }
            return root;
        }
        else{
            if(Key<root->Key)
            {
               root->left= deleteDataHelper(Key,root->left);
            }
            else{
                root->right=deleteDataHelper(Key,root->right);
            }
            return root;
        }

    }
    public:
    void deleteData(int key)
    {
        if(!Search(key)){
            cout<<"No key Found"<<endl;
            return;

        }
        root=deleteDataHelper(key,root);

    }

*/

};
