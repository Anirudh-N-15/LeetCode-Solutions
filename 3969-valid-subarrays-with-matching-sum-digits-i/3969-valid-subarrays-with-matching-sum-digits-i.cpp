class Solution {
public:
    pair<int,int> firstAndLastDigit(long long num) {
        pair<int,int> ans ;
        ans.first = num % 10 ;

        while(num > 0) {
            ans.second = num % 10 ;
            num /= 10 ;
        }

        return ans ;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size() ;
        int count = 0;

        for(int i = 0; i < n; i++) {
            long long sum = 0 ;
            for(int j = i; j < n; j++) {
                sum += nums[j] ;

                pair<int,int> ans = firstAndLastDigit(sum) ;

                if(ans.first == x && ans.second == x) {
                    count++ ;
                }
            }
        }
        return count ;
    }
};