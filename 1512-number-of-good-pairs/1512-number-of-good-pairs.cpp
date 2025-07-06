class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count =0;

        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i] == nums[j]){
                    count++ ;
                }
            }
        }
        return count ;
    }
};