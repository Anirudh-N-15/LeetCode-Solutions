class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans =0,right =0;
        int n = nums.size();
        unordered_map<int,int> count;
        unordered_set<int> distinct(nums.begin(),nums.end());
        int distCount = distinct.size();

        for(int left=0; left < n;left++){
            if(left > 0){
                count[nums[left-1]]-- ;
                if(count[nums[left-1]] == 0){
                    count.erase(nums[left-1]);
                }
            }
            while((right < n) && (count.size() < distinct.size())) {
                count[nums[right]]++ ;
                right++ ;
            }
            if(count.size() == distCount){
                ans += (n - right + 1);
            }
        }
        return ans ;
    }
};