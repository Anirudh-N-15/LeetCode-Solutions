class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = box[j][i] ;
            }
        }

        for(int i=0;i<n;i++) {
            reverse(ans[i].begin(),ans[i].end());
        }

        for(int j=0; j < m; j++ ) {
            int lowest = n-1;

            for(int i=n-1; i >=0 ; i--) {
                if(ans[i][j] == '#') {
                    ans[i][j] = '.' ;
                    ans[lowest][j] = '#';
                    lowest-- ;
                }
                if(ans[i][j] == '*') {
                    lowest = i -1;
                }
            }
        }

        return ans ;
    }
};