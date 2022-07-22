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
        
        ListNode* temp  = head;
        vector<int> krina ; 
        
        
        while(temp!= NULL){
            krina.push_back(temp->val);
            temp = temp ->next; 
        }
        
        temp = head;
        for(int  i = 0 ; i < krina.size();i++){
            if(krina[i]<x){
                temp->val = krina[i];
                temp = temp->next;
            }
        }
        for(int  i = 0 ; i < krina.size();i++){
            if(krina[i]>=x){
                temp->val = krina[i];
                temp = temp->next;
            }
        }
        
        return head;
        
    }
};