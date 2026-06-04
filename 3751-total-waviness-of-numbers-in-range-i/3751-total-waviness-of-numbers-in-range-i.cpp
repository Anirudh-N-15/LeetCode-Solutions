class Solution {
public:
    int checkWaviness(int num) {
        int count = 0;
        string s = to_string(num);
        int n = s.size() ;

        for(int i=1; i < n -1;i++) {
            if(s[i] > s[i-1] && s[i] > s[i+1]) {
                count++ ;
            } else if( s[i] < s[i-1] && s[i] < s[i+1]) {
                count++ ;
            }
        }
        return count ;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;
        if(num2 < 100) return 0;

        for(int i = num1; i <= num2; i++) {
            ans += checkWaviness(i);
        }
        return ans ;
    }
};