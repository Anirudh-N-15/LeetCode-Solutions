class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long ans = 0;
        for (const int& num : nums) {
            int count = 0;
            long long sum = 0;
            for (int i = 1; i*i <= num; i++) {
                if (num % i == 0) {
                    int d1 = i;
                    int d2 = num/i ;
                    count ++ ;
                    sum += d1 ;

                    if(d1 != d2) {
                        count++ ;
                        sum += d2 ;
                    }

                    if(count > 4) break ;
                }
            }

            if (count == 4) {
                ans += sum;
            }
        }
        return ans;
    }
};