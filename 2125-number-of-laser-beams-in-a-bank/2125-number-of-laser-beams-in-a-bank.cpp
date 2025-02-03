class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> count;

        for(int i=0;i<n;++i){
            int laser = 0;
            for(int j=0;j<bank[i].size();++j){
                if(bank[i][j] == '1'){
                    laser++ ;
                }
            }
            if(laser != 0){
                count.push_back(laser);
            }
        }

        int m= count.size();
        int ans =0;
        for(int i=1;i<m;++i){
            ans = ans + (count[i-1] * count[i]); 
        }

        return ans ;
    }
};