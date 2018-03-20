#include"TrieNodeClass.h"
#include<string>
class Trie{
private:
    TrieNode *root;
    int numWords;
public:
    Trie(){
        root=NULL;
        numWords=0;

    }
private:
    void insertHelper(TrieNode*root,string word)
    {
        /*char ch=word[0];
        if(ch=='\0')
        {
            root->isEnd=true;
            return;

        }

        if(root->children[ch-'a']==NULL)
        {
            TrieNode*newNode=new TrieNode(ch);
            root->children[ch-'a']=newNode;
        }
    insertHelper(root->children[ch-'a'],word.substr(1));

    return;*/
    ///base case
    if(word.length()==0)
    {
        root->isEnd=true;
        return;

    }
    char chToInsert=word[0];
    int index=ch-'a';
    TrieNode*child;
    if(root->children[index]!=NULL)
    {
        child=root->children[index];
    }
    else{

        child=new TrieNode(chToInsert);
        root->children[index]=child;
    }
    ///recursive call

    insertHelper(child,word.substr(1));
    return;

    }
    bool searchWord(TrieNode*root,string word){
        ///base case
        if(word.length()==0)
        {
            if(root->isEnd==true) return true;
            else return false;
        }
        /// small calculation
        char firstCharacter=word[0];
        TrieNode*child;
        int index=firstCharacter-'a';
        child=root->children[index];
        if(child==NULL)
        {
            return false;

        }
        else{
            ///recursive call
            return searchWord(child,word.substr(1));
        }
    }
    TrieNode*removeWord(TrieNode*root,string word)
    {
        if(word.length()==0){
            root->isEnd=false;
            for(int i=0;i<26;i++)
            {
                if(root->children[i]!=NULL)
                {
                    return root;
                }
            }
            delete root;root=NULL;
            return root;
        }
        int index=word[0]-'a';
        TrieNode*child=root->children[index];
        if(child==NULL)
        {
            return root;
        }
        else{

            root->children[index]=removeWord(child,word.substr(1));
            return root;
        }
    }
public:

    void insertWord(string word){
        ///word.lower();
        numWords++;
        return insertHelper(root,word);

    }
    bool searchWord(string word){
      return searchWord(root,word);
    }
    void removeWord(string word){
    root= removeWord(root,word);


    }



};
