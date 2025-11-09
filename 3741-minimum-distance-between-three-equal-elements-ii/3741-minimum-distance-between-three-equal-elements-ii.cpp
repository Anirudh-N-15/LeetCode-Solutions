//This question requires us to leverage a lot of details. We use a map of list since 
//we only need to check equal numbers in the list and its guaranteed to be only the 
//adjacent indices in the list in the map.Therefore slide a window across the list
//and you will reach the answer.

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> mp ;

        for(int i=0;i<n;i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX ;
        for(const auto & [num,vec] : mp) {
            auto &v = vec ;

            if(v.size() >= 3) {
                for(int i=2;i<v.size();i++) {
                    ans = min(ans,2*(v[i] - (v[i-2])));
                }
            }
        }
        return ans == INT_MAX ? -1 : ans ;
    }
};