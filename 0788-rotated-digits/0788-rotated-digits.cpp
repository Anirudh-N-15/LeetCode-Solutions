class Solution {
public:
    bool isGoodNumber(int num) {
        bool hasValidRotate = false;

        while (num > 0) {
            int d = num % 10;

            if (d == 3 || d == 4 || d == 7)
                return false;
            if (d == 2 || d == 5 || d == 6 || d == 9)
                hasValidRotate = true;

            num /= 10;
        }

        return hasValidRotate;
    }

    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isGoodNumber(i)) count++;
        }
        return count;
    }
};