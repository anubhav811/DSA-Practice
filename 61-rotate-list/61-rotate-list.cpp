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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0 || !head->next) return head;
        
        /* retrieve length of linked list */
        int len = 1;
        ListNode* tail = head;
        
        for (ListNode* curr=head; curr->next != nullptr; curr=curr->next)
        {
            len++;
            tail = tail->next;
        }
        
        k %= len;
        
        if (k == 0) return head; /* no rotation */
        
        int newhead = len - k;
        
        
        ListNode *prev = head, *p1 = head;
        
        for (int i = 0; i < newhead - 1; ++i)
        {
            prev = prev->next; p1 = p1->next;    
        }
        
        p1 = p1->next;
        
        /* redirect */
        tail->next = head;
        prev->next = nullptr;
        
        return p1; /* new head */
  }
};