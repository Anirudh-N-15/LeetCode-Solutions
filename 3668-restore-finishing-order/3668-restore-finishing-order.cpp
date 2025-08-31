class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> uset(friends.begin(),friends.end());
        vector<int> ans ;
        for(const int& num : order ) {
            if(uset.find(num) != uset.end()) {
                ans.push_back(num);
            }
        }
        return ans ;
    }
};