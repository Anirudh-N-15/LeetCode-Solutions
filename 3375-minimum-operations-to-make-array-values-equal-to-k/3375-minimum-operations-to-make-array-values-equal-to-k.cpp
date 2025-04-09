class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if(*min_element(nums.begin(),nums.end()) < k) return -1;

        vector<int> count(101);
        for(int i=0;i<nums.size();i++) {
            count[nums[i]]++ ;
        }
        int distinct = 0;
        for(int & num : count){
            if(num >= 1){
                distinct++ ;
            }
        }
        return (*min_element(nums.begin(),nums.end()) > k)? distinct : distinct - 1 ;
    }
};