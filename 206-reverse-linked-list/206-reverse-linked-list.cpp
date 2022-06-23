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
       
    void recursive(ListNode* &head, ListNode* curr, ListNode* prev)
    {
      if(curr==NULL){
          head=prev;
          return ;
      }
      ListNode* forward =  curr->next;
      recursive(head,forward,curr);
      curr->next = prev;
    }
    
    ListNode* reverseList(ListNode* head) {
        // Approach 1
        // return iterative(head);
        
        // Approach 2
        ListNode* curr = head;
        ListNode* prev = NULL;
        recursive(head,curr,prev);
        return head;
    }
};