class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans(n,0);

        for(int i=0;i<n;i++) {
            long long required = (success + spells[i] - 1)/spells[i] ;
            auto index = lower_bound(potions.begin(),potions.end(),required);
            ans[i] = m - static_cast<int>(index - potions.begin()) ;
        }
        return ans ;

    }
};