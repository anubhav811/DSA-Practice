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
        
        // APPROACH 2: OPTIMAL -> TC:O(N)+O(N)+O(N) SC:O(N)
        
    // STEP 1 : MAKE A COPY NODE AND INSERT IT BETWEEN 2 NODES
        // EXAMPLE : 1' WILL BE INSERTED BETWEEN 1 and 2
        
        Node* itr = head;
        while(itr){
            Node* copy = new Node(itr->val);
            copy->next = itr->next;
            itr->next = copy;
            
        // for iterating now we have to move the itr node                                       twice as we have inserted a new node between them
            
            itr=itr->next->next;
        }
        
    // STEP 2 : SMARTLY COPY THE RANDOM POINTERS
        
        // bringing itr back to start
        itr=head;
        
        while(itr){
            if(itr->random!=NULL)
                itr->next->random=itr->random->next;
            itr=itr->next->next;
        }
        
    // STEP 3 : Pointing next pointers for deep copy
        // we have to
        
        itr=head;
        
        Node* pseudoHead = new Node(0);
        Node* copy = pseudoHead; 
        Node* copyItr = pseudoHead;
        Node* fwd ;

        while (itr != NULL) {
            fwd = itr->next->next;

        // extract the copy
            copy = itr->next;
            copyItr->next = copy;
            copyItr = copy;

        // restore the original list
            itr->next = fwd;

            itr = fwd;
      }

      return pseudoHead->next; 
        
        
        

        // Approach 1: HASMAP TC: O(N)+O(N)  SC:O(N)
        
//         map<Node*, Node*> m;
        
//         Node* itr = head;
        
//         // in the map make key as the curr node and its copy as the value.
//         // ONLY COPY THE val not the two pointers
//         while (itr) {
            
//            m[itr] =new Node(itr->val);  //key = itr and value = new Node(itr->val)
           
//            itr = itr->next;
//         }
//         // Keeping itr back to start(head)
//         itr = head;
        
//         // iterate and then assign pointers to the copy by using map
//         while (itr!=NULL) {
            
//             m[itr]->next = m[itr->next];
//             m[itr]->random = m[itr->random];
//             itr=itr->next;
//        }
//         return m[head];

        
    }
};