/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        
        
        // Approach 1: HASMAP\
        
        map<Node*, Node*> m;
        
        Node* itr = head;
        
        // in the map make key as the curr node and its copy as the value.
        // ONLY COPY THE val not the two pointers
        while (itr) {
            
             m[itr] =new Node(itr->val);  //key = itr and value = new Node(itr->val)
           
            itr = itr->next;
        }
        // Keeping itr back to start(head)
        itr = head;
        
        // iterate and then assign pointers to the copy by using map
        while (itr!=NULL) {
            
            m[itr]->next = m[itr->next];
            m[itr]->random = m[itr->random];
            itr=itr->next;
       }
        return m[head];

        
    }
};