class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> umap;

        for(int i=0;i<s.size();i++) {
            if(umap.find(s[i]) == umap.end()) {
                umap[s[i]] = {i,1};
            } else {
                int count = umap[s[i]].second + 1 ; 
                umap[s[i]] = {i,count} ;
            }
        }   
        int ans = s.size();
        for(const auto ch : umap) {
            if(ch.second.second == 1){
                ans = min(ans,ch.second.first);
            }
        }
        return ans == s.size() ? -1 : ans ;
    }
};