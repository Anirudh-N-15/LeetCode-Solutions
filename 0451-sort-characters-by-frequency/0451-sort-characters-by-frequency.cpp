class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> freq(128);
        int n = s.size();
        for(const char &c : s) {
            freq[c].first++ ;
            freq[c].second = c ;
        }

        sort(freq.begin(),freq.end());
        string res = "" ;

        for(int i = 127; i >= 0; i--) {
            res.append(freq[i].first,freq[i].second);
            
        }
        return res ;
    }
};