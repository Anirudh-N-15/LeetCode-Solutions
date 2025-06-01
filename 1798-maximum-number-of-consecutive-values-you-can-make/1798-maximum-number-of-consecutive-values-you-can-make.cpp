class Solution {
public:

    int getMaximumConsecutive(vector<int>& coins) {
        int n = coins.size();
        int sum = 0;
        sort(coins.begin(),coins.end());

        for(int i=0;i<n;++i) {
            if(sum + 1 >= coins[i]) {
                sum += coins[i] ;
            } else 
                break;
        }
        return sum+ 1;
    }
};