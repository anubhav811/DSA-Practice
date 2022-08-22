class LRUCache {
public:
    
    // doubly linked list 
    class Node{
        public:
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int _key,int _val){
            this->key = _key;
            this->val = _val;
        }
    };
    // capacity
    int cap; 
    
    // for storing key and node address
    map<int,Node*> mp ;
    
    // Making nodes for head and tail
    
    Node* head= new Node(-1,-1);
    
    Node* tail= new Node(-1,-1);

    LRUCache(int capacity) {
        cap = capacity ;
        head->next = tail;
        tail->prev = head;   
    }
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(Node* delNode){
        Node* delprev= delNode->prev;
        Node* delnext= delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int _key, int value) {
         if(mp.find(_key)!=mp.end()){
            Node* existingNode = mp[_key];
            mp.erase(_key);
            deleteNode(existingNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(_key,value));
        mp[_key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */ 