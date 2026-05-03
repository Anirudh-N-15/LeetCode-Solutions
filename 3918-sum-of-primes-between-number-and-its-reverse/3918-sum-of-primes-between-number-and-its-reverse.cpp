class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;

        if (n <= 3) return true;

        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        string s = to_string(n) ;
        reverse(s.begin(),s.end());
        int r = stoi(s);
        long long ans = 0;

        for(int i=min(n,r); i <= max(n,r); i++) {
            if(isPrime(i)) {
                ans += i ;
            }
        }
        return ans ;
    }
};