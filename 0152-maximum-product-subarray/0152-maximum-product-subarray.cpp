class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0],currMin = nums[0],maxProd = nums[0];

        for(int i=1;i<n;++i){
            int temp = max({nums[i],currMax*nums[i],currMin*nums[i]});

            currMin = min({nums[i],currMax*nums[i],currMin*nums[i]});

            currMax = temp ;

            maxProd = max(maxProd,currMax);
        }

        return maxProd ;
    }
};