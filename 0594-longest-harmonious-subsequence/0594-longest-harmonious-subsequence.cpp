class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(const int &num : nums) {
            freq[num]++ ;
        }
        int ans = 0;

        for(auto it : freq) {
            int count = it.second;
            if(freq.find(it.first + 1) != freq.end()) {
                count += freq[it.first +1] ;
                ans = max(ans,count);
            }
        }
        return ans ;
    }
};