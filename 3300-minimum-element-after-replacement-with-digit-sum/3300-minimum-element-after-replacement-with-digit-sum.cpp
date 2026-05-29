class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX ;
        for(int num : nums) {
            int sumNum = 0;
            while(num > 0) {
                sumNum += num % 10 ;
                num /=10 ;
            }
            ans = min(ans,sumNum);
        }
        return ans ;
    }
};