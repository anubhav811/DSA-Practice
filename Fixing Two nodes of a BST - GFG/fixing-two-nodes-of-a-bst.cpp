//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isBST(Node* n, int lower, int upper)
{
    if (!n) return true;
    if ( n->data <= lower || n->data >= upper ) return false;
    return (  isBST( n->left, lower, n->data )  &&  isBST( n->right, n->data, upper )  );
}

bool compare( Node* a, Node* b, vector<pair<int, int>> &mismatch )
{
    if ( !a && !b ) return true;
    if ( !a || !b ) return false;

    if ( a->data != b->data )
        mismatch.push_back( pair<int, int> (a->data, b->data) );

    return ( compare( a->left, b->left, mismatch ) && compare( a->right, b->right, mismatch ) );
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:    
    Node* prev;
    Node* first_i;
    Node* first_j;
    Node* second;
  public:
    void inorder(struct Node* root){
        
        if(!root) return ;
        
        // left side 
        inorder(root->left);
        
        // curr node . main business
        // check if curr node's value is greater then prev's
        if(prev and root->data < prev->data){
            
            // check if we have had a first violation
            if(!first_i){
                // We didnt have a violation yet so we can mark it here
                first_i = prev;
                first_j = root;
            }
            else{
                // We have had a first violation . So this is a second violation
                second = root;
            }
        }
        // Marking the curr node as prev , so far the next node this curr node can act as prev
        prev = root;
        
        // right side
        inorder(root->right);
    }
    void correctBST( struct Node* root )
    {
        first_i = NULL;
        first_j = NULL;
        second = NULL;
        prev = new Node(INT_MIN);
        
        inorder(root);
        
        if(first_i and second) swap(first_i->data, second->data);
        else if(first_i and first_j) swap(first_i->data,first_j->data);

    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string s;
        getline(cin, s);

        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);

        Solution ob;
        ob.correctBST(root);

        // check 1: is tree now a BST
        if ( ! isBST(root, INT_MIN, INT_MAX) )
        {
            cout << "0\n";
            continue;
        }

        // check 2: comparing with duplicate tree

        vector<pair<int, int>> mismatch;
        // a vector to store data of mismatching nodes

        if ( ! compare( root, duplicate, mismatch) )
        {
            // false output from this function indicates change in structure of tree
            cout << "0\n";
            continue;
        }

        // finally, analysing the mismatching nodes
        if ( mismatch.size() != 2 || mismatch[0].first != mismatch[1].second || mismatch[0].second != mismatch[1].first )
            cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}

// } Driver Code Ends