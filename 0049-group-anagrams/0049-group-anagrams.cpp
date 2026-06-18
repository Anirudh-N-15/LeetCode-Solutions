class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap ;

        for(const auto &str : strs) {
            vector<int> count(26,0) ;

            for(const char &ch : str) {
                count[ch - 'a']++ ;
            }

            string s = "";

            for(int i = 0; i < 26; i++) {
                s += to_string(count[i]) + '#' ;
            }

            umap[s].push_back(str) ;
        }

        vector<vector<string>> ans ;

        for( auto &[key,val] : umap) {
            ans.push_back(val) ;
        }

        return ans ;
    }
};