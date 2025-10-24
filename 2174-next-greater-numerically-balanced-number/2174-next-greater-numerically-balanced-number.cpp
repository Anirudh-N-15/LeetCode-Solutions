class Solution {
public:
    bool solve(int x) {
        string s = to_string(x);
        vector<int> vec(10, 0);

        for (const char& c : s) {
            vec[c - '0']++;
        }

        for (const char& c : s) {
            if (c == 0 || vec[c - '0'] != c - '0') {
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1;; i++) {
            if (solve(i)) {
                return i;
            }
        }
        return -1;
    }
};