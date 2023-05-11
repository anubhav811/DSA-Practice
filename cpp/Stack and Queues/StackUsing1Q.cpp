#include<bits/stdc++.h>
using namespace std;
class StackWith1Q{

    private:
        queue<int> q1;
    public:
        StackWith2Q(){

        }

        void push(int n){
            q1.push(n);
            int k = q1.size() -1 ;
            while(k--){
                q1.push(q1.front());
                q1.pop();
            }
        }

        int pop() {
            if(q1.empty()) return -1;
            int val = q1.front();
            q1.pop();
            return val;
        }

        int top(){
            if(q1.empty()) return -1;
            int val = q1.front();
            return val;
        }

        int size(){
            return q1.size();
        }

        bool empty(){
            return q1.empty();
        }

       // TC : O(N) ; SC : ~ O(N)

        void print(){
            
            int k = q1.size();
            while(k--){
                cout<<q1.front();
                q1.push(q1.front());
                q1.pop();
            }
        }
};
int main()
{

    StackWith1Q s =  StackWith1Q();

    s.push(1);
    s.push(2);
    s.push(4);
    s.pop();
    s.push(3);

    s.print();

    return 0;
}