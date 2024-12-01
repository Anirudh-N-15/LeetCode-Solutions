class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MIN ;
        int firstSell = 0 ;
        int secondBuy = INT_MIN ;
        int secondSell = 0 ;

        for(int i=0;i<prices.size();++i){
            firstBuy = max(firstBuy,-prices[i]);

            firstSell = max(firstSell,prices[i]+firstBuy);

            secondBuy = max(secondBuy,firstSell-prices[i]);

            secondSell = max(secondSell,prices[i]+secondBuy);
        }
        return secondSell ;
    }
};