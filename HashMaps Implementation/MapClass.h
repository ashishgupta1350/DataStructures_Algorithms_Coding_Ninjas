#include<string>
#include<vector>
template<typename V>
class MapNode{
public:
    string key;
    int value;
    MapNode<V>*next;
    MapNode(string key,int value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~MapNode()
    {

        delete next;
    }

};
template<typename V>
class myMap{
private:
    MapNode<V>** buckets;
    int Count;
    int numBuckets;
public:
    myMap()
    {
        Count=0;
        numBuckets=5;
        buckets=new MapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++)
        {
            buckets[i]=NULL;

        }

    }
private:
    int getBucketIndex(string key)
    {
        int hashCode=0;
        int currentCoeff=1;
        for(int i=key.size()-1;i>=0;i--)
        {
            hashCode=hashCode+key[i]*currentCoeff;
            hashCode=hashCode%numBuckets;
            currentCoeff*=37;
            currentCoeff=currentCoeff%numBuckets;

        }

        return hashCode%numBuckets;
    }
public:

   rehash()
   {
       MapNode<V>**temp=buckets;
            buckets=new MapNode<V>* [2*numBuckets];
            for(int i=0;i<2*numBuckets;i++)
            {
                buckets[i]=NULL;

            }
            numBuckets*=2;
            Count=0;
            for(int i=0;i<numBuckets/2;i++)
            {
                MapNode<V>*head=temp[i];
                while(head!=NULL)
                {
                    Insert(head->key,head->value);
                    head=head->next;

                }
            }
            for(int i=0;i<numBuckets/2;i++){
                delete temp[i];

            }
            delete temp;
            temp=NULL;

   }
    void Insert(string key,int value)
    {
        ///check if load factor > 0.7
        if(Count/(numBuckets*1.0)>0.7)
        {
            rehash();
        }

        int bucketIndex=getBucketIndex(key);
        MapNode<V>*head=buckets[bucketIndex];

        while(head!=NULL)
        {
            ///during this traversal if you happen to find the key
            if(head->key==key)
            {
                head->value=value;
                return;
            }
            head=head->next;
        }
        head=buckets[bucketIndex];
        MapNode<V>*node=new MapNode<V>(key,value);
        node->next=head;
        buckets[bucketIndex]=node;
        Count++;
        return;


    }
    int getSize/*returns number of nodes inserted*/()
    {
        return Count;
    }
    V getValue(string key)
    {
        int bucketIndex=getBucketIndex( key);
        MapNode<V>*head=buckets[bucketIndex];
        while(head!=NULL)
        {

            ///during this traversal if you happen to find the key
            if(head->key==key)
            {
                return head->value;
            }
            head=head->next;
        }

        return 0;

    }
    V Remove(string key)
    {
         int bucketIndex=getBucketIndex( key);
        MapNode<V>*head=buckets[bucketIndex];
        MapNode<V>*prev=NULL;
        while(head!=NULL)
        {
            ///during this traversal if you happen to find the key
            if(head->key==key)
            {
                if(prev==NULL)
                {
                    buckets[bucketIndex]=head->next;

                }else{
                    prev->next=head->next;
                }
                V value=head->value;
                head->next=NULL;
                delete head;
                Count--;
                return value;

            }
            prev=head;
            head=head->next;
        }

        return 0;

    }

    bool Search(string key)
    {
        int bucketIndex=getBucketIndex(key);

        MapNode<V>* tail=buckets[bucketIndex];
        while(tail!=NULL)
        {
            if(tail->key==key)
            {
                return true;
            }
            tail=tail->next;

        }
        return false;

    }

};
