class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int i, j,count=0;
        int n = words.size();
        for (int i = 0; i < n -1; ++i) {
            for(int j=i+1;j<n;++j) {
                if(isPrefixAndSuffix(words[i],words[j]) == true) {
                    count++ ;
                }
            }
        }
        return count ;
    }

private:
    bool isPrefixAndSuffix(string word1, string word2) {
        int n = word1.size(), m = word2.size() ;
       if(n > m) return false ;

       string prefix = word2.substr(0,n);
       if(prefix != word1) return false ;

       string suffix = word2.substr(m-n,n);
       if(suffix != word1) return false ;

        return true ;
    }
};