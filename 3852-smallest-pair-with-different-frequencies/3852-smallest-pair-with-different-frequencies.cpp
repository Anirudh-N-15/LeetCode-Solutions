class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int> mp ;
        for(const int &num : nums) {
            mp[num]++ ;
        }

        vector<int> ans ;
        int currFreq = mp.begin()->second ;
        ans.push_back(mp.begin()->first);

        for(const auto &[num,freq] : mp) {
            if(ans.size() == 2){
                break ;
            }
            if(num > ans[0] && freq != currFreq) {
                ans.push_back(num) ;
            }
        }

        if(ans.size() == 1){
            return {-1,-1} ;
        }
        return ans ;
    }
};