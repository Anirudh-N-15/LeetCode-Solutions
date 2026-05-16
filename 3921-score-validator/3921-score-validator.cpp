class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans(2,0);

        for(const string &s : events) {
            if(ans[1] == 10) {
                return ans ;
            }
            if(s == "W") {
                ans[1]++ ;
            } else if(s == "WD" || s == "NB") {
                ans[0]++ ;
            } else if(s >= "0" && s <= "6") {
                int num = stoi(s);
                ans[0] += num ;
            }
            
        }
        return ans ;
    }
};