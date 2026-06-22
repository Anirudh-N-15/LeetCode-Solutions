class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> umap ;
        unordered_map<char,int> freq ;

        for(const char &ch : target) {
            umap[ch]++ ;
        }

        for(const char &ch : s) {
            if(umap.find(ch) != umap.end()) {
                freq[ch]++ ;
            }
        }

        int ans = INT_MAX ;
        for(const char &ch : target) {
            ans = min(ans,freq[ch]/umap[ch]);
        }

        return ans ;
    }
};