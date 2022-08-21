class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        int min =INT_MAX;
        int curr = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]> curr){
                total += prices[i]-curr; 
            }
            curr = prices[i];
        }
        return total;
    }
};