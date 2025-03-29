Code-:

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
class LRUCache {
public:
    class Node
    {
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key,int val)
        {
            this->key=key;
            this->val=val;
            prev=NULL;
            next=NULL;
        }
    };
    
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    unordered_map<int,Node*>m;
    int cap;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* newNode)
    {
        Node* temp=head->next;
        head->next=newNode;
        newNode->prev=head;
        newNode->next=temp;
        temp->prev=newNode;
    }

    void deleteNode(Node* delNode)
    {
        Node* prevNode=delNode->prev;
        Node* nextNode=delNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
           Node* resNode=m[key];
           int res=resNode->val;
           m.erase(key);
           deleteNode(resNode);
           addNode(resNode);
           m.insert({key,head->next});
           return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
           Node* node=m[key];
           m.erase(key);
           deleteNode(node);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode=new Node(key,value);
        addNode(newNode);
        m.insert({key,head->next});
    }
};


int main() {
    LRUCache cache(2); // Capacity of 2

    cache.put(1, 10);
    cache.put(2, 20);
    cout << "get(1): " << cache.get(1) << endl; // Should return 10
    
    cache.put(3, 30); // Removes key 2
    cout << "get(2): " << cache.get(2) << endl; // Should return -1 (not found)
    
    cache.put(4, 40); // Removes key 1
    cout << "get(1): " << cache.get(1) << endl; // Should return -1 (not found)
    cout << "get(3): " << cache.get(3) << endl; // Should return 30
    cout << "get(4): " << cache.get(4) << endl; // Should return 40
    
    return 0;
}



