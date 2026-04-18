class Solution {
public:
    int reverse(string a) {
        int n = a.size() ;
        int i=0,j=n-1 ;

        while(i<j) {
            swap(a[i],a[j]);
            i++ ;
            j-- ;
        }
        return stoi(a) ;
    }
    
    int mirrorDistance(int n) {
        int rev = reverse(to_string(n));

        return abs(n - rev) ;
    }
};