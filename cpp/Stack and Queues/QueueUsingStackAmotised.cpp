#include<bits/stdc++.h>
using namespace std;
class MyQueue {
    private:
        stack<int> input;
        stack<int> output;
    public:
        MyQueue() {}
        
        // O(1)
        void push(int x) {
            input.push(x);
        }
        
        // O(1) and only sometimes O(N)  ~ "O(1) amotised"
        int pop() {
            if(!output.empty()){
                int val = output.top();
                output.pop();
                return val;
            }

            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            
            int val = output.top();
            output.pop();
            return val;
        }
        
        // O(1) and only sometimes O(N)  ~ "O(1) amotised"
        int peek() {
            if(!output.empty()){
                return output.top();
            }

            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            
            int val = output.top();
            return val;
        }
        
        bool empty() {
            return (input.empty() && output.empty());
        }
};
int main()
{

    return 0;
}