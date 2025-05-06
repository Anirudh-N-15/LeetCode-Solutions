class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return {} ;
        int size = *max_element(nums.begin(),nums.end());
        vector<int> count(size+1,0);
        vector<int> prefix(size+1,0);
        int res = 0;
        for(int &num : nums){
            count[num]++ ;
        }

        for(int i=0;i<count.size();++i){
            if(count[i] == 0){
                res = 0;
            } else {
                res++ ;
                prefix[i] = res ;
            }
        }
        
        return *max_element(prefix.begin(),prefix.end());
    }
};