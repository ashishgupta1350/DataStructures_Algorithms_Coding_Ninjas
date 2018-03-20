template<typename T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode<T>*left;
    BinaryTreeNode<T>*right;

    BinaryTreeNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

    void printTree()
    {
        if(this==NULL) return;
        cout<<data<<" ";
        left->printTree();
        right->printTree();
        return;

    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }

};
