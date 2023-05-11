#include<bits/stdc++.h>
using namespace std;
void MyStack ::push(int x) 
{
    StackNode* node = new StackNode(x);
    
    if(top==NULL){
        top = node;
    }
    else{
        node->next = top;
        top = node;
    }
    
    
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    if(top==NULL) return -1;
    
    int val = top->data;
    top=top->next;
    return val;

}

int main()
{

    return 0;
}