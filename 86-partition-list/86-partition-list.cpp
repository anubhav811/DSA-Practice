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
    ListNode* partition(ListNode* head, int x) {
        
        // Approach 2 : Two Pointers  O(1) 
        
        ListNode* less  = new ListNode(0);
        ListNode* great = new ListNode(0);
        ListNode* less_head = less;
        ListNode* great_head = great;

    
        while(head!=NULL)
        {
            if(head->val < x){
                less->next = head;
                less = less->next;
                head = head->next;
                less -> next = NULL;
            }
            else{
                great->next = head;
                great = great->next;
                head = head->next;
                great -> next = NULL;
            }
            
        }
        
        less -> next  = great_head->next;
        
        return less_head->next;
        
        
        // Approach 1 :  Brute O(n) .  Traverse and put elements in vector in order and then make list 
//         ListNode* temp  = head;
//         vector<int> krina ; 
        
        
//         while(temp!= NULL){
//             krina.push_back(temp->val);
//             temp = temp ->next; 
//         }
        
//         temp = head;
//         for(int  i = 0 ; i < krina.size();i++){
//             if(krina[i]<x){
//                 temp->val = krina[i];
//                 temp = temp->next;
//             }
//         }
//         for(int  i = 0 ; i < krina.size();i++){
//             if(krina[i]>=x){
//                 temp->val = krina[i];
//                 temp = temp->next;
//             }
//         }
        
//         return head;
        
    }
};