class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans ;

        for(int i=0;i<=n/2;i++) {
            if(i == 0) {
                ans.push_back(i);
            } else {
                ans.push_back(-i);
                ans.push_back(i);
            }
        }
        return ans ;
    }
};