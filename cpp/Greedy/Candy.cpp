#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        vector<int> candies(N,1);
        for(int i = 1 ; i < N ; i++){
            if(ratings[i]>ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }
        
        for(int i = N-2 ; i >=0 ; i--){
            if(ratings[i]>ratings[i+1]){
                candies[i] = max(candies[i],candies[i+1]+1);
            }
        }
        
        int sum = 0;
        for(int i = 0 ; i < N ; i++){
            sum += candies[i];
        }
        return sum;
    }
};
int main()
{

    return 0;
}