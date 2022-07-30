/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
        
        // Naive Approach 1:  Brute Force TC: O(m*n)  SC : O(1)

        //         while(head2 != NULL) {
        //         ListNode* temp = head1;
        //         while(temp != NULL) {
        //             //if both nodes are same
        //             if(temp == head2) return head2;
        //             temp = temp->next;
        //         }
        //         head2 = head2->next;
        //         }
        //         //intersection is not present between the lists return null
        //         return NULL;

        
        
        // Naive Approach 2: Hashing  TC : O(n + logn) SC : O(n)

        //          unordered_set<ListNode *> st;
        //          while(head1!=NULL)
        //          {        
        //              st.insert(head1);
        //              head1=head1->next;
        //          }
        //          while(head2!=NULL){
        //              if(st.find(head2) != st.end()){
        //                  return head2;
        //              }
        //              head2 = head2->next;
        //          }
        //          return NULL;
        
        
        // Optimal Approach 1  : Difference of len TC: O(n) SC: O(1)

		         int n = 0;
		         int m = 0;
		         ListNode* ptr1 = head1;
		         ListNode* ptr2 = head2;
		         while(ptr1 != NULL){
			            n++;
			            ptr1 = ptr1 -> next;
		         }
		         while(ptr2 != NULL){
        	            m++;
        	            ptr2 = ptr2 -> next;
		         }
		         int t = abs(n - m);
		         if(n > m){
			            while(t){
				            head1 = head1 -> next;
				            t--;
			             }
		         }
		         else{
		 	        while(t){
				            head2 = head2 -> next;
				            t--;
			              }
		          }
		         while(head1 != NULL and head2 != NULL){
			            if(head1 == head2){
				            return head1;
			             }
        	            head1 = head1 -> next;
        	            head2 = head2 -> next;
		         }
		          
                 return NULL;
        
        
        // Optimal Approach 2  : Shift to other's head
 
        //     	    ListNode *ptr1 = headA;
        // 		    ListNode *ptr2 = headB;
        // 		    while(ptr1 != ptr2){
        // 			    if(ptr1 == NULL){
        // 				    ptr1 = headB;
        // 			    }   
        // 			    else{
        // 				    ptr1 = ptr1 -> next;
        // 			    }
        // 			    if(ptr2 == NULL){
        // 				    ptr2 = headA;
        // 			    }
        // 			    else{
        // 				    ptr2 = ptr2 -> next;
        // 			    }
        // 		    }
        // 		    return ptr1;

       
	}
};
