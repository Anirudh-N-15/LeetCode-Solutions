class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int mod = 1e9 + 7;
        int sum = 0;
        int n = s.size();
        vector<int> cnt(26, 0);

        for (const char& c : s) {
            cnt[c - 'a']++;
        }

        for (int i = 0; i < t; i++) {
            vector<int> nxt(26);
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % mod ;
            for (int j = 2; j < 26; j++) {
                nxt[j] = cnt[j -1] ;
            }
            cnt = move(nxt) ;
        }

        for (const int& i : cnt) {
            sum  = (sum + i) % mod;
        }

        return sum ;
    }
};