#include<bits/stdc++.h>
using namespace std;

class MyStack{
        int top ;
        int arr[100];
    public:
        MyStack(){
            top=-1;
        }

        void push(int x){
            arr[top++]=x;
        }

        void pop(){
           ifcout<<(top==-1) cout<<"Empty";
           arr[top--];
           
        }

        int peek(){
            return (top==-1) ? -1 : arr[top];
        }

        int size(){
            return top+1;
        }

        bool empty(){
            return top==-1;
        }

        void print(){
            if(top==-1) cout<<"Empty";
            else
                for(int i=top;i>=0;i--) cout<<arr[i]<<" ";
        }

};
int main()
{

    MyStack s =  MyStack();

    s.push(5);
    s.push(4);
    s.push(223);
    s.pop();
    cout<<"Top: "<<s.peek();
    cout<<endl;
    s.print();
}