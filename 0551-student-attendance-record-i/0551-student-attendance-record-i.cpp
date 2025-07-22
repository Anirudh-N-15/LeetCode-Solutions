class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        int countA = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                if (i < n - 1) {
                    if (s[i + 1] == 'A') {
                        return false;
                    }
                }
                countA++;
            } else if (s[i] == 'L') {
                if (i < n - 2) {
                    if (s[i + 1] == 'L' && s[i + 2] == 'L') {
                        return false;
                    }
                }
            }
            if (countA > 1) {
                return false;
            }
        }
        return true;
    }
};