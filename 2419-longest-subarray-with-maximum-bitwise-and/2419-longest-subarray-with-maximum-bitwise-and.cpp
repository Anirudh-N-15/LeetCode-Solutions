class Solution {
public:

    int maximum(int a,int b){
        return a>b ? a:b;
    }

    int longestSubarray(vector<int>& nums) {
        int currentlength = 0;
        int maxlength = 0;

        int max = *max_element(nums.begin(),nums.end());

        for(int i=0;i<nums.size();++i){
            if(nums[i]==max){
                currentlength++ ;
                maxlength = maximum(currentlength,maxlength);
            }
            else
            currentlength = 0;
        }
        return maxlength ;
    }
};