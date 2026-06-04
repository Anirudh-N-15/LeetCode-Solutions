class Solution {
public:
    int passwordStrength(string password) {
        int strength = 0;
        unordered_set pass(password.begin(), password.end());

        for (const char& ch : pass) {
            if (ch >= 'a' && ch <= 'z') {
                strength++;
            } else if (ch >= 'A' && ch <= 'Z') {
                strength += 2;
            } else if (ch >= '0' && ch <= '9') {
                strength += 3;
            } else {
                strength += 5;
            }
        }
        return strength ;
    }
};