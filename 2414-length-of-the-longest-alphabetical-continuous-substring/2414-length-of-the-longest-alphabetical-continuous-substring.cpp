class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int left = 0, ans = 1, curr = 1;

        for (int right = 1; right < n; right++) {
            if(s[right] == s[right-1] + 1) {
                curr = right - left + 1;
            } else {
                left = right ;
                curr = 1;
            }
            ans = max(ans,curr);
        }
        return ans ;
    }
};