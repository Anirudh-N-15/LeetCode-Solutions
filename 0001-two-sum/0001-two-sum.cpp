class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mp ;

        for(int i=0;i<nums.size();++i){
            int index1 = nums[i];
            int index2 = target - nums[i] ;

            if(mp.find(index2)!=mp.end()){
                return {mp[index2],i} ;
            }
            mp[index1] = i ;
        }
        return {-1,-1} ;
    }
};