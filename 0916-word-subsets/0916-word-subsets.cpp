class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>check(26,0);

        for(string& s : words2) {
            vector<int>temp(26,0);
            for(const char& c : s) {
                int index = c - 'a' ;
                temp[index]++ ;
                check[index] = max(check[index],temp[index]);
            }
        }
        vector<string>ans;

        for(string &s : words1) {
            vector<int> temp(26,0);
            for(const char& c : s) {
                int index = c - 'a' ;
                temp[index]++ ;
            }
            bool flag = true;
            for(int i=0;i<26;++i) {
                if(temp[i] < check[i]){
                    flag = false ;
                    break;
                }
            }
            if(flag) ans.push_back(s);
        }
        return ans ;
    }
};