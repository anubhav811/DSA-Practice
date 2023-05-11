#include<bits/stdc++.h>
using namespace std;

class MyQueue{
    private:
        int cnt ;
        int arr[100];
        int front;
        int rear;
    public:
        void push(int x){
            if(cnt<100){
                arr[rear%100] = x;
                rear++;
                cnt++;
            }
            else{
                cout<<"Capacity full";
            }
        }

        void pop(){
            if(front==rear) return -1;
            cnt--;
            arr[front%n] = -1;
        }

        int peek(){
            if(cnt==0) return -1;
            if(front==rear) return -1;
            return arr[front%100];
        }

        bool empty(){
            if(front==rear) return true;
            return false;
        }
        
        int size(){
            return cnt;
        }

        void print(){
            for(int i=front ; i<rear-1;i++){
                cout<<arr[front%100]<<" ";
            }
        }

}
int main()
{

    return 0;
}