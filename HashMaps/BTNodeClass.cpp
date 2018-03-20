template<typename T>
class BinaryTreeNode{
public:
    int Key;
    T data;
    BinaryTreeNode<T>*left;
    BinaryTreeNode<T>*right;

    BinaryTreeNode(int Key,T data)
    {
        this->Key=Key;
        this->data=data;
        left=NULL;
        right=NULL;
    }
    BinaryTreeNode(int data)
    {

        this->data=data;
        left=right=NULL;
    }

   /* void printTree()
    {
        if(this==NULL) return;
        cout<<data<<" ";
        left->printTree();
        right->printTree();
        return;

    }
*/
    ~BinaryTreeNode()
    {

        delete left;
        delete right;
    }

};
