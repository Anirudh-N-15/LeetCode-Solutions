class Solution {
public:
    vector<string> partitionString(string s) {
        set<string> seen;
        vector<string> ans;

        for(int i=0;i<s.size();) {
            string curr = "";
            
            for(int j=i;j<s.size();j++) {
                curr += s[j];

                if(seen.find(curr) == seen.end()) {
                    seen.insert(curr);
                    ans.push_back(curr);
                    i = j+1 ;
                    break;
                } else {
                    i = j+1 ;
                }
            }
        }
        return ans ;
    }
};