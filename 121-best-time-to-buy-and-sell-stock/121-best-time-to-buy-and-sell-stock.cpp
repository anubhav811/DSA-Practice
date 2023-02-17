class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX;
        int profitToday = 0;
        int profit = 0;
        
        for(int i=0;i<prices.size();i++){
            minPrice = min(minPrice,prices[i]);
            
            profit = max(profit,prices[i]-minPrice);
          
        }
        return profit;
    }
    
};