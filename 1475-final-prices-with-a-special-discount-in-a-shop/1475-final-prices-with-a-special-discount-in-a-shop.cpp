class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size() ;
        vector<int> result(n);
        
        int i ;
        for(i=0;i< n-1;++i){
            int j =i+1 ;
            if(prices[j]<= prices[i]){
                result[i] = abs(prices[i] - prices[j]) ;
            }
            else{
                while(prices[j]>prices[i] && j < n-1){
                    j++ ;
                }
                if(prices[j] <= prices[i]){
                    result[i] = abs(prices[i] - prices[j]) ;
                }
                else{
                    result[i] = prices[i] ;
                }
            }
        }
        result[i] = prices[i] ;
        return result ;
    }
};