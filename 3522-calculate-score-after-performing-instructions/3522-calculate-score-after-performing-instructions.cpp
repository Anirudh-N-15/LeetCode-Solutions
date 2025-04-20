class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = values.size();
        vector<pair<bool,string>> instr(n);
        for(int i=0;i<n;++i){
            instr[i].first = false;
            instr[i].second = instructions[i];
        }
        long long ans = 0;
        int i = 0;
        while(i < n && i >= 0){
            if(instr[i].first == true){
                return ans; 
            }
            instr[i].first = true;

            if(instr[i].second == "add"){
                ans += values[i];
                i++ ;
            }
            else if(instr[i].second == "jump"){
                if(values[i] == 0) break;
                i += values[i];
            }
        }
        return ans ;
    }
};