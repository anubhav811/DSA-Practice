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

        // Approach 1 : Find length and then find mid and then traverse
//         ListNode* temp1 = head;
//         int l = 0;
//         while(temp1!=NULL){
//             temp1 = temp1->next;
//             l++;
//         }

//         int mid = l/2;
        
//         ListNode* temp2 = head;
//         int c = 0;
//         while(c<mid){
//             temp2 = temp2->next;
//             c++;
//         }
//         return temp2;
    }
};