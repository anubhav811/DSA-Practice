#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;
    Node(int key,int val){
        this->key = key;
        this->val = val;
        cnt = 1;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;
    
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void remove(Node* curr){
        Node* beforeToBeRemoved = curr->prev;
        Node* afterToBeRemoved = curr->next;
        beforeToBeRemoved->next = afterToBeRemoved;
        afterToBeRemoved->prev = beforeToBeRemoved;
        size--;
    }

    void insert(Node* curr){
        Node* temp = head->next;
        curr->next = temp;
        curr->prev = head;
        head->next = curr;
        temp->prev = curr;
        size++;
    }
};

class LFUCache {
public:
    map<int,Node*> keyNode;
    map<int,List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int currSize;
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }
    
    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->remove(node);
        // if we were removing from least freq and the freq list is empty then we need to update minFreq
        if(node->cnt==minFreq and freqListMap[node->cnt]->size == 0){
            minFreq++ ;
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        // now increase the count
        node->cnt += 1;
        // add this node to the higherfreqlist
        nextHigherFreqList->insert(node);
        // update the freq map
        freqListMap[node->cnt] = nextHigherFreqList;
        // update the key node map
        keyNode[node->key] = node;
    }
    int get(int key) {
        if(keyNode.find(key)==keyNode.end()) return -1;
        Node* node = keyNode[key];
        int val = node->val;
        updateFreqListMap(node);
        return val;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0) return; // leetcode edge case bkchodi
        if(keyNode.find(key)!=keyNode.end()){
            Node* node = keyNode[key];
            // update the value
            node->val = value;
            updateFreqListMap(node);
        }
        else{
            if(currSize==maxSizeCache){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->remove(list->tail->prev);
                currSize--;
            }
            // new value to be added
            // so,
            minFreq = 1;
            List* list = new List();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                list = freqListMap[minFreq];
            }
            Node* node = new Node(key,value);
            list->insert(node);
            keyNode[key] = node;
            freqListMap[minFreq] = list;
            currSize++;
        }
    }
};
int main()
{

    return 0;
}