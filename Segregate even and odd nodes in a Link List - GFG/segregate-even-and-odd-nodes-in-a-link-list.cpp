//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        Node* lastOdd = NULL;
        Node* lastEven = NULL;
        Node* itr = head;
        Node* oddStart = NULL;
        Node* evenStart = NULL;
        
        while(itr){
            if(itr->data%2==0){
                if(lastEven==NULL){
                    lastEven = itr;
                    evenStart = itr;
                }else{
                    lastEven->next = itr;
                    lastEven = lastEven->next;
                }
            }
            else{
                if(lastOdd==NULL){
                    lastOdd= itr;
                    oddStart = itr;
                }
                else{
                    lastOdd->next = itr;
                    lastOdd = lastOdd->next;
                }
            }
            
            itr=itr->next;
        }
        
        if(lastEven)
            lastEven->next = oddStart;
        if(lastOdd)
            lastOdd->next = NULL;
        
        return (evenStart) ? evenStart : oddStart;
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends