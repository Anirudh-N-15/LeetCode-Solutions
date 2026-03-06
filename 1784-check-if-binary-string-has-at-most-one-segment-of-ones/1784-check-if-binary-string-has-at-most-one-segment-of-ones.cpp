class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (flag == true) {
                    return false;
                }
                flag = true;
                while (i < n && s[i] == '1') {
                    i++;
                }
                i--;
            }
        }
        return true;
    }
};