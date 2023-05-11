#include<bits/stdc++.h>
using namespace std;
class StackWith2Q{

    private:
        queue<int> q1;
        queue<int> q2;
    public:
        StackWith2Q(){

        }

       // TC : O(N) ; SC : ~ O(N)
        void push(int n){

            q2.push(n);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }

            swap(q1,q2);
        }

        int pop(){

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

            while(!q1.empty()){
                cout<<q1.front()
                q2.push(q1.front());
                q1.pop();
            }

            swap(q1,q2);
        }


}
int main()
{

    return 0;
}