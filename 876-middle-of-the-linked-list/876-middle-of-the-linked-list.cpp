/*
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
    ListNode* middleNode(ListNode* head) {
        // tortoise hare approach
        
        ListNode* slow = head; 
        ListNode* fast = head;
        while (fast!=NULL && fast->next!=NULL){
            slow = slow->next; 
            fast = fast->next->next;
        }
        return slow;


        // Approach 1 
//         ListNode* dummy = head;
//         int l = 0;
//         while(dummy!=NULL){
//             dummy = dummy->next;
//             l++;
//         }
        
//         int mid = l/2 ;
        
//         dummy = head;
//         int c=0;
//         while(c<mid){
//             dummy = dummy->next;
//             c++;
//         }
//         return dummy;
        
    }
};