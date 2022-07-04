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
    ListNode* reverse(ListNode* ptr) {
    ListNode* pre=NULL;
    ListNode* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}

bool isPalindrome(ListNode* head) {
    if(head==NULL||head->next==NULL) return true;
        
    ListNode* slow = head;
    ListNode* fast = head;
        
    while(fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
        
    slow->next = reverse(slow->next);
    slow = slow->next;
        
    while(slow!=NULL) {
        if(head->val != slow->val) return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}

//    Approach 1 
    
    //bool isPalindrome(ListNode* head) {
        
        
//         vector<int> arr;
//         while(head != NULL) {
//             arr.push_back(head->val);
//             head = head->next;
//         }
//         for(int i=0;i<arr.size()/2;i++){
//             if(arr[i] != arr[arr.size()-i-1]){
//                 return false; 
//             }
//         }
        
//         return true;

//     }
};