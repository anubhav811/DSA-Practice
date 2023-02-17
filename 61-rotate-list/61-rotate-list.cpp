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
        
        if(head==NULL || k==0 || head->next==NULL) return head;
                                                  
        // find length of linked list
        int len = 1;
        ListNode* itr  = head;
        
        
        while(itr->next != NULL)
        {
            itr=itr->next;
            len++;
        }
        
        // now at this point itr is at the last node , now we will point the last nde            to the head of the linked list
        
        itr->next=head;
        
        // if k is greater than k , we will get the required no of rotation
        k = k%len;
        
        // the distance we have to travel to reach the breaking point   
        int bp = len - k;
          
        // reaching the BP
        while(bp>0){
            itr=itr->next;
            bp--;
            }
        
        // now itr has reached the breaking point 
        
        // head of the modified list will be kept at the node after BP
        // and the BP will be pointed now to NULL
        
        head=itr->next;
        itr->next=NULL;
        
        return head;
       
    }
};