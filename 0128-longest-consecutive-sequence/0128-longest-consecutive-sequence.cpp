class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> uset(nums.begin(),nums.end());

        int count = 1,longest = 1;

        for(const int &num : uset){
            if(uset.find(num -1) == uset.end()) {
                int number = num ;
                count = 1;
                while(uset.find(number+1) != uset.end()){
                    count++ ;
                    number++ ;
                }
                longest = max(longest,count);
            }
        }
        return longest ;
    }
};