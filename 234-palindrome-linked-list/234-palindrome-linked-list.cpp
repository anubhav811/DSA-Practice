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
    ListNode* reverse(ListNode *head)
    {
        
        ListNode *current = head;
        ListNode *prev = NULL, *next = NULL;
  
        while (current != NULL) 
        {           
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode *fast, *slow;
        fast = slow = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *temp = reverse(slow->next);  // reversing the half linked list
        slow->next = temp;  // joining the reversed list to the main list
        
        slow= slow->next;
        fast = head;
        
        while(head != NULL && slow != NULL)
        {
            if(fast->val != slow->val)
                return false;
            
            fast = fast->next;
            slow = slow->next;
        }
        
        return true;
    
        
    }
};