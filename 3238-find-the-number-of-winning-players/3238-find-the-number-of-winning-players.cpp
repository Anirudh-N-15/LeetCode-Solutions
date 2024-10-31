class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>>v(n,vector<int>(11,0));
        int a=0;
        for(int i=0;i<pick.size();i++){
            v[pick[i][0]][pick[i][1]]++;
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]>i){
                    a++;
                    break;
                }
            }
        }
        return a;
    }
};