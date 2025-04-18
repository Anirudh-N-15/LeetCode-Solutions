class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string res = "1";
        for(int k=2;k<=n;++k){
            string temp = "";
            int count = 1;
            for(int i=0;i<res.size();++i){
                if(i < res.size() && res[i] == res[i+1]){
                    count++ ;
                } else {
                    temp += to_string(count);
                    temp += res[i];
                    count = 1;
                }
            }
            res = temp ;
        }
        return res ;
    }
};