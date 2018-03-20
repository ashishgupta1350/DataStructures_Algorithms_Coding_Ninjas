


class BST {
	// Complete this class
	private:
	BinaryTreeNode<int>*root;
	public:
	BST()
    {
        root=NULL;

    }
    ~BST()
    {
        delete root;
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
    void insert(int data){
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
        cout<<"L:"<<root->left->data<<",";
    if(root->right)
    {
        cout<<"R:"<<root->right->data;

    }
    cout<<endl;
    printTreeProper(root->left);
    printTreeProper(root->right);
    return;
}
public:
    void printTree(){
        printTreeProper(root);

    }

    /*BinaryTreeNode<int>* minimum(BinaryTreeNode<int>*root)
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
    BinaryTreeNode<int>* deleteDataHelper(int data,BinaryTreeNode<int>*node){
        if(node==NULL) return node;
        if(node->data==data)
        {
            if(!(node->left||node->right))
            {
               delete node;
                return NULL;

            }
            else if(!node->left&&node->right)
            {

                return node->right;

            }
            else if(!node->right&&node->left)
            {
                return node->left;
            }
            else{
                BinaryTreeNode<int>*nodeR=minimum(node->right);
                node->data=nodeR->data;
                nodeR->right=deleteDataHelper(nodeR->data,nodeR->right);
                return node;
            }

        }
        else{
            if(data<node->data)
            {
               node->left= deleteDataHelper(data,node->left);
            }
            else{
                node->right=deleteDataHelper(data,node->right);
            }
            return node;
        }

    }
    */

    BinaryTreeNode<int>*deleteData(int data,BinaryTreeNode<int>*node)
    {
        if(node==NULL) return NULL;
        if(data<node->data)
        {
           /// cout<<" i also reach here "<<endl;
            ///printTreeProper(root);
            node->left=deleteData(data,node->left);
            return node;
        }
        else if(data>node->data)
        {
            node->right=deleteData(data,node->right);
            return node;
        }
        else{
          ///  cout<<"I come at this point, here temps data is data to be deleted : "<<endl;
            BinaryTreeNode<int>*temp=NULL;
            if(root->left==NULL&&root->right==NULL)
            {
                delete node;
                return NULL;
            }
            else if(node->left&&!node->right)
            {
                temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else if(!node->left&&node->right){
                 temp=node->right;
                node->right=NULL;
                delete node;
                return temp;
            }
            else {
                BinaryTreeNode<int>*temp=NULL;
                ///cout<<"I come here "<<endl;
                temp=node->right;
                while(temp->left!=NULL)
                {
                    temp=temp->left;
                }
                int rightMin=temp->data;
                ///temp now points at minimum of these nodes
                node->data=rightMin;

                node->right=deleteData(rightMin,node->right);
                return node;
            }

        }
    }

    public:
    void deleteData(int data)
    {
        root=deleteData(data,root);

    }

};


