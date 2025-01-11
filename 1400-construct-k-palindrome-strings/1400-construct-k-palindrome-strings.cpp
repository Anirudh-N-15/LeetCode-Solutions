class Solution {
public:
    bool canConstruct(string s, int k) {
        int n =s.size();
        int count =0 ;
        if(k > n) return false ;
        else if(k == n) return true ;
        else {
            unordered_map<char,int> umap ;
            for(const char &ch : s) {
                umap[ch]++ ;
            }
            for(auto it : umap) {
                if(it.second % 2 != 0) {
                    count++ ;
                }
            }
        }

        return (count > k) ? 0: 1 ;
    }
};