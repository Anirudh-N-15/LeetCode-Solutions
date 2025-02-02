class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,profit ;

        for(int i=1;i<prices.size();++i){
            if(prices[i-1] < prices[i]){
                profit = prices[i] - prices[i-1] ;
                maxprofit += profit ;
            }   
        }

        return maxprofit ;
    }
};