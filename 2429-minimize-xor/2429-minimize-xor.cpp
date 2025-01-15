class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = __builtin_popcount(num1);
        int m = __builtin_popcount(num2);
        int x = num1;

        for (int i = 0; i < 32; ++i) {
            if (n > m && ((1 << i) & num1)) {
                x ^= 1 << i;
                --n;
            }

            if (n < m && !((1 << i) & num1)) {
                x ^= 1 << i;
                ++n;
            }
        }
        return x;
    }
};