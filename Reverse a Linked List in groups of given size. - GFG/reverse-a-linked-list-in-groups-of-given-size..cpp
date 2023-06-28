//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node* getKth(struct node* head,int k){
        
        while(head->next and k>1){
            head = head->next;
            k--;
        }
        return head;
    }
    struct node* reverseLL(struct node* head){
        struct node* curr = head;
        struct node* prev = NULL;
        while(curr){
            struct node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    struct node *reverse (struct node *head, int k)
    { 
       
        struct node* dummy = new node(0);
        dummy->next = head;
        struct node* prevGrpTail = dummy;
        
        while(head){
            struct node* currGrpStart = head;
            struct node* currGrpEnd   = getKth(head,k);
            
            struct node* nextGrpStart = currGrpEnd->next;
            currGrpEnd->next = NULL;
            prevGrpTail->next = reverseLL(currGrpStart);
            
            
            struct node* newGrpTail = currGrpStart;
            newGrpTail->next = nextGrpStart;
            prevGrpTail = newGrpTail;
            head = nextGrpStart;
        }
            
        struct node* ans= dummy->next;
        delete dummy;
        return ans;
        }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends