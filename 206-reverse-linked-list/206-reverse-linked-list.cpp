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
    ListNode* iterative(ListNode* &head)
    {
        if(head==NULL || head->next == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev=curr;
            curr=forward;
            }
        head = prev;
        return head;
    }
       
    ListNode* recursive(ListNode* &head)
    {
        if(head==NULL || head->next == NULL) return head;
        
        ListNode* newHead = recursive(head->next);
        
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        
        // Approach 1
        // return iterative(head);
        
        // Approach 2
        return recursive(head);

    }
};