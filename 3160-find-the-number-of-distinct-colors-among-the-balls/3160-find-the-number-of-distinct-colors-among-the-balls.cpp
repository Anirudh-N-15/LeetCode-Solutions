class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        ans.reserve(n);
        unordered_map<int,int> color, balls;

        for(int i=0;i<n;++i) {
            int ball = queries[i][0], col = queries[i][1];

            if(balls.count(ball)) {
                int prevCol = balls[ball];
                if(--color[prevCol] == 0){
                    color.erase(prevCol);
                }
            }
            balls[ball] = col;
            color[col]++ ;

            ans.push_back(color.size());
        }
        return ans ;
    }
};