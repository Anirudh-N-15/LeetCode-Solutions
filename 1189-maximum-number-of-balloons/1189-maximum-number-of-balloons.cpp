class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> umap ;

        for(const char &ch : text) {
            if(ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n')
            umap[ch]++ ;
        }

        int b = umap['b'], a = umap['a'], l = umap['l']/2 , o = umap['o']/2, n = umap['n'] ;

        return min({b,a,l,o,n}) ;
    }
};