//So the idea here is that whenever we encounter a character 'b' then we increment the 
//counter.While the counter is not zero and we encounter char 'a' then we  decrement
//the counter whilst increasing our answer because that is the number of a's we have
//to remove that occurs after b. 

class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, count = 0;

        for(const char &c : s) {
            if(c == 'b') {
                count++ ;
            } else if(count) {
                count-- ;
                ans++ ;
            }
        }
        return ans ;
    }
};

//We could also use DP, just find the longest common Palindromic subsequence and then
//subtract it from the length of the original string which will fetch us the number of
//chars to be deleted.

// class Solution {
//   public:
//     int minDeletions(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//         string t = s;
//         reverse(t.begin(),t.end());
        
//         for(int i=1;i<=n;i++) {
//             for(int j=1;j<=n;j++) {
//                 if(s[i-1] == t[j-1]) {
//                     dp[i][j] = dp[i-1][j-1] + 1;
//                 } else {
//                     dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
//                 }
//             }
//         }
//         return n - dp[n][n] ;
        
//     }
// };

