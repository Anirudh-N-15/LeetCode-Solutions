class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> result ;

        if(p.size() > s.size()) return result; 
        vector <int> scount(26,0) , pcount(26,0);

        for(char ch : p){
            pcount[ch - 'a']++ ;
        }

        int window = p.size();

        for(int i=0;i<window;++i){
            scount[s[i] - 'a']++ ;
        }

        if(pcount == scount){
            result.emplace_back(0);
        }

        for(int i = window; i<s.size();++i){
            scount[s[i] - 'a']++ ;
            scount[s[i - window]- 'a']-- ;

            if(scount == pcount) result.emplace_back(i - p.size() + 1) ;
        }

        return result ;

    }
};