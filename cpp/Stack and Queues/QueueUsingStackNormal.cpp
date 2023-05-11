#include<bits/stdc++.h>
using namespace std;
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
 
    MyQueue() {
    }
    
    // O(2*N)
    void push(int x) {

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

    }
    
    // O(1)
    int pop() {
        if(s1.empty()) return -1;
        
        int value = s1.top();
        s1.pop();
        return value;
    }
    
    // O(1)
    int peek() {
        if(s1.empty()) return -1;
        
        int value = s1.top();
        return value;
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main()
{

    return 0;
}