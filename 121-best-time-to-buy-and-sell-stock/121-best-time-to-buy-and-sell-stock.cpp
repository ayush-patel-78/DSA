class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int min = 1000000000; 
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min){
                min=prices[i];
            }
            if(prices[i]-min>profit){
                profit=prices[i]-min;
            }
            
            
        }
        return profit;
        
    }
};