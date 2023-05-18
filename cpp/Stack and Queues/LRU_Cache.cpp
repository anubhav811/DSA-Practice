#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key,int val){
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};
class LRUCache {
public:
    Node* head;
    Node* tail;
    int sz ;
    map<int,Node*> mp;

    void remove(Node* curr){
        Node* beforeToBeRemoved = curr->prev;
        Node* afterToBeRemoved = curr->next;
        beforeToBeRemoved->next = afterToBeRemoved;
        afterToBeRemoved->prev = beforeToBeRemoved;
        mp.erase(curr->key);
        curr->prev = NULL;
        curr->next = NULL;
    }

    void insert(Node* curr){
        Node* temp = head->next;
        curr->next = temp;
        curr->prev = head;
        head->next = curr;
        temp->prev = curr;
        mp[curr->key] = curr;

    }
    LRUCache(int capacity) {
        sz = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        Node* toBeRemoved = mp[key];
        int val = toBeRemoved->val;
        // removal
        remove(toBeRemoved);
        // inserting as Most Recently used
        insert(toBeRemoved);

        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()) 
            remove(mp[key]);
        
        if(mp.size()==sz)
            remove(tail->prev); // remove LRU
        
        // Now insert updated value
        insert(new Node(key,value));
    }
};

int main()
{

    return 0;
}