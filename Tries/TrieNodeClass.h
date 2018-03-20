class TrieNode{
  private:
    char data;
    TrieNode **children;
    bool isEnd;
  public:
    TrieNode()
    {
        children=new TrieNode* [26];
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;

        }
        isEnd=false;
    }
    TrieNode(char data)
    {
        this->data=data;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;

        }
        isEnd=false;


    }

};

