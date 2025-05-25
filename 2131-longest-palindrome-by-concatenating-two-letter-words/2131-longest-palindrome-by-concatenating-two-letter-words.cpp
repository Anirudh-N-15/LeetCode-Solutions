class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        bool sameChar = false;
        int ans = 0;

        for(string word : words) {
            mp[word]++ ;
        }

        for(auto &p : mp) {
            string word = p.first ;
            int count = p.second;

            string rev = word;
            reverse(rev.begin(),rev.end());

            if(word == rev) {
                ans += (count/2) * 4;

                if(count % 2 == 1) {
                    sameChar = true;
                }
            } else if(mp.find(rev) != mp.end()) {
                int pairs = min(count,mp[rev]);
                ans += pairs * 4;
                mp[word] = 0;
                mp[rev] = 0;
            }
        }
        if(sameChar) {
            ans += 2;
        }
        return ans ;
    }
};