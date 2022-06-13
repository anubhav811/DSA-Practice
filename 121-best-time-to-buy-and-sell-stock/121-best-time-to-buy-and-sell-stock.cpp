class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX;
        int profitToday = 0;
        int profit = 0;
        
        for(int i=0;i<prices.size();i++){
            // if(prices[i]<min){
            //     min = prices[i];
            // }
            minPrice = min(minPrice,prices[i]);
            profit = max(profit,prices[i]-minPrice);
            // profitToday = prices[i] - min ;
            // if(profit<profitToday){
            //     profit = profitToday;
            // }
        }
        return profit;
    }
    
};