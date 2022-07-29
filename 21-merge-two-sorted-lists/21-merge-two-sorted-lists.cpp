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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // Approach 1 : Use extra list
        if(l1==NULL && l2==NULL) return NULL;
        
        if(l1 == NULL) return l2; 

        if(l2 == NULL) return l1;
        
        ListNode* res = new ListNode();
        ListNode* resHead = res;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                resHead->next = new ListNode(l1->val);;
                l1 = l1->next;
            }
            else {
                resHead->next = new ListNode(l2->val);;
                l2 = l2->next;
            }
            resHead = resHead->next;
        }
        
        if(l1!=NULL)
            resHead->next = l1;
        else
            resHead->next = l2;
        
        
        return res->next;

        
        // Approach 2 : In Place

//         if(l1 == NULL) return l2; 

//         if(l2 == NULL) return l1;

//         if(l1->val > l2->val) swap(l1,l2);

//         ListNode* res = l1;

//         while(l1 != NULL && l2 != NULL) {
 
//             ListNode* temp = NULL;

//             while(l1 != NULL && l1->val <= l2->val) {

//                 temp = l1;//storing last sorted node  
//                 l1 = l1->next;
//             }

//             // link previous sorted node with 
//             // next larger node in list2
//             temp->next = l2;
//             std::swap(l1,l2);
//         }

//         return res;
    }
      
    
};