class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        int n = corridor.size() ;
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') {
                pos.push_back(i);
            }
        }
        
        if (pos.size() % 2 or pos.size() == 0) {
            return 0;
        }
        
        long res = 1;
        for (int i = 2; i < pos.size(); i += 2) {
            int gapLength = pos[i] - pos[i - 1];
            res = (res * gapLength) % mod;
        }

        return res;
    }
};