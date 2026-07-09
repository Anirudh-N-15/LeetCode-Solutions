class Solution {
public:
    int digitRange(int x) {
        pair<int,int> ans = {INT_MAX,INT_MIN} ;

        while(x > 0) {
            ans.first = min(ans.first,x % 10) ;
            ans.second = max(ans.second,x % 10) ;
            x /= 10 ;
        }
        return ans.second - ans.first ;
    }

    int maxDigitRange(vector<int>& nums) {
        unordered_map<int,vector<int>> umap ;
        int maxRange = INT_MIN ;

        for(const int &num : nums) {
            int ans = digitRange(num) ;
            maxRange = max(maxRange,ans);
            umap[ans].push_back(num) ;
        }

        int res = 0;
        for(const int &num : umap[maxRange]) {
            res += num ;
        }
        return res ;
    }
};