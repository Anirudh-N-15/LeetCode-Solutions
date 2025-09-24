class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0" ;
        string ans = "" ;
        if( numerator > 0 ^ denominator > 0) ans += "-" ;
        long long num = labs(numerator);
        long long den = labs(denominator);

        long long q = num/den ;
        long long r = num % den ;
        ans += to_string(q) ;

        if(r == 0) return ans ;

        ans += "." ;

        unordered_map<long,int> umap ;
        while(r != 0) {
            if(umap.find(r) != umap.end()) {
                int pos = umap[r] ;
                ans.insert(pos,"(");
                ans += ")" ;
                break ;
            } else {
                umap[r] = ans.size() ;
                r *= 10 ;
                q = r/den ;
                r = r % den ;
                ans += to_string(q) ; 
            }
        }
        return ans ;
    }
};