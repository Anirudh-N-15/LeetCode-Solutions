class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev =0,ans = 0;

        for(string &s : bank) {
            int count = 0;
            for(const char &ch : s) {
                if(ch == '1') {
                    count++ ;
                }
            }
            if(count != 0) {
                ans += (prev * count) ;
                prev = count ;
            }
        }
        return ans ;
    }
};