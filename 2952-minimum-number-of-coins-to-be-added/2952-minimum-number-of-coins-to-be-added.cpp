class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        long long sum = 1;
        int count = 0,i=0;

        while(sum <= target) {
            if(i < coins.size() && sum >= coins[i]) {
                sum += coins[i] ;
                i++ ;
            } else {
                sum += sum ;
                count++ ;
            }
        }
        return count ;
    }
};