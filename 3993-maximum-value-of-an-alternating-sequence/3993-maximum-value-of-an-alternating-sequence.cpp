class Solution {
public:
    long long maximumValue(int n, int s, int m) {

        long long ans = (long long)s + (long long)(n/2)* (long long)m - (long long)(n/2 -1);
        
        return n == 1 ? s : ans;
    }
};