/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 
    ListNode* reverseKGroup(ListNode* head, int k) {
        
    ListNode* cursor = head;
    for(int i = 0; i < k; i++){
        if(cursor == nullptr) return head;      
        cursor = cursor->next;
    }    
    // step 1: reverse k nodes
    
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    int count =  0;

    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
        
    // step 2: recursion 
    head->next = reverseKGroup(curr,k);
        
    return prev;
        
    }
};