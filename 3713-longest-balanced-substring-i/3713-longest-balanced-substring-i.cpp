class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        int n = s.size() ;

        for(int i=0;i<n;i++) {
            unordered_map<char,int> umap ;

            for(int j=i;j<n;j++) {
                umap[s[j]]++ ;

                bool flag = false ;
                auto it = umap.begin() ;
                int cnt = it->second ;

                for(auto it : umap) {
                    if(cnt != it.second) {
                        flag = true ;
                        break ;
                    }
                }
                if(flag == true ) {
                    continue ;
                }
                ans = max(ans,j-i + 1);
            }
        }
        return ans ;
    }
};