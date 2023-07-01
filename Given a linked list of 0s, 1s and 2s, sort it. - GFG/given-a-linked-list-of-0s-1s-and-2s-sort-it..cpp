//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    Node* segregate(Node *head) {
        // Approach 2
        Node* head0=new Node(-1);
        Node* tail0=head0;
        Node* head1=new Node(-1);
        Node* tail1=head1;
        Node* head2=new Node(-1);
        Node* tail2=head2;

        Node* itr=head;
        while(itr!=NULL)
        {
            if(itr->data==0)
            {
                tail0->next = itr;
                tail0=tail0->next;
            }
            else if(itr->data==1)
            {
                tail1->next = itr;
                tail1=tail1->next;
            }
            else
            {
                tail2->next = itr;
                tail2=tail2->next;
            }
            itr=itr->next;
        }
        
        if(head1->next)
            tail0->next = head1->next;
        else
            tail0->next = head2->next;
        
        tail1->next = head2->next;
        tail2->next = NULL;
        
        head = head0->next;
        
        delete head0,head1,head2;
        
        return head;
        // Approach 1 (Data replacement)
        // Node* itr=head;
        // int a=0,b=0,c=0;
        // while(itr){
        //     if(itr->data==0) a++;
        //     else if(itr->data==1) b++;
        //     else c++;            
        //     itr=itr->next;
        // }
        // itr=head;
        // while(itr){
        //     if(a!=0){
        //         itr->data=0;
        //         a--;
        //     }
        //     else if(b!=0){
        //         itr->data=1;
        //         b--;
        //     }
        //     else{
        //         itr->data=2;
        //         c--;
        //     }
            
        //     itr=itr->next;
        // }
        
        // return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends