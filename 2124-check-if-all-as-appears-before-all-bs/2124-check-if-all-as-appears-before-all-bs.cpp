class Solution {
public:
    bool checkString(string s) {
        int count = 0, ans =0;

        for(const char &c : s) {
            if(c == 'b') {
                count++ ;
            } else if(count) {
                ans-- ;
                count-- ;
            }
        }
        return ans < 0 ? false : true ;
    }
};