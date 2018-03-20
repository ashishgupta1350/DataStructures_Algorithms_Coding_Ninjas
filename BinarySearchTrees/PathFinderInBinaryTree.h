#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)

void print(vector<int> *a,int Size)
{
    FOR(i,0,Size) cout<<a[i]<< " ";cout<<endl;
}

#include<vector>
bool hasPath(BinaryTreeNode<int> *root, vector<int>& arr, int x)
{
    // if root is NULL
    // there is no path
    if (!root)
        return false;

    // push the node's value in 'arr'
    arr.push_back(root->data);

    // if it is the required node
    // return true
    if (root->data == x)
        return true;

    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (hasPath(root->left, arr, x) || hasPath(root->right, arr, x))
        return true;

    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false
    arr.pop_back();
    return false;
}

int lcaBinaryTree(BinaryTreeNode<int>*root,int val1,int val2)
{
    vector<int> v1,v2;
    bool isPathThere1=hasPath(root,v1,val1);
    bool isPathThere2=hasPath(root,v2,val2);

    if(isPathThere1==false&&isPathThere2==false) return -1;
    else if(isPathThere1==false) return val2;
    else if(isPathThere2==false) return val1;
    else{
            int flag=0;
            int returnVal=-1;
        for(int i=0;i<v1.size();i++)
        {

            for(int j=0;j<v2.size();j++)
            {
                if(v1[i]==v2[j]){
                    flag=1; returnVal=v1[i]; break;
                }
                if(flag==1) break;
            }
        }

    return returnVal;
    }

}
