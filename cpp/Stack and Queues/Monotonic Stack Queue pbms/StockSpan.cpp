#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    stack<pair<int,int>> s; // {NGL,idx}
    vector<int> v; // store value
    int i ;
    StockSpanner(){
        i=0;
    }
    int next(int price){
        while(!s.empty() && s.top().first<=price)
        {
            s.pop();
        }
        if(s.empty()) v.push_back(-1);
        else v.push_back(s.top().second);

        s.push({price,i});
        
        return i-v[i++];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main(){

}