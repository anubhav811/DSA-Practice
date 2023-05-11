#include<bits/stdc++.h>
using namespace std;
void MyQueue:: push(int x)
{
    QueueNode* node = new QueueNode(x);
    if(rear==NULL){
        front = node;
        rear = node;
    }
    else{
        rear->next = node;
        rear = node;
    }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    QueueNode *temp =front;
    
    //if queue is empty, we return NULL.
    if(front ==NULL)
        return -1;

    //if more than one node is present, we move temp one node ahead and 
    //delete front. we also update front as new temp.
    if(temp->next !=NULL)
    {
        temp=temp->next;
        int k = front->data;
        delete(front);
        front = temp;
        return k;
    }
    //else we delete front and make both rear and front as NULL.
    else
    {
        int k=front->data;
        delete(front);
        front=rear=NULL;
        //returning the popped element.
        return k;
    }
}

int main()
{

    return 0;
}