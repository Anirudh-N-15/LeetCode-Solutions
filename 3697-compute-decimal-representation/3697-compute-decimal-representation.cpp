class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        string num = to_string(n) ;
        int size = num.size();
        vector<int> ans ;
        int exp = 0;
        for(int i = size-1; i >= 0; i--) {
            int res = (num[i] - '0') * pow(10,exp) ;
            if(res != 0) 
                ans.push_back(res);
            exp++ ;
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans ;
    }
};