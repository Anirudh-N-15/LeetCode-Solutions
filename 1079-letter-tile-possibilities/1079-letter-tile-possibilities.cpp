class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(const char &c : tiles) {
            freq[c - 'A']++ ;
        }
        return buildChar(freq);
    }
private:
    int buildChar(vector<int>& freq) {
        int totalCount = 0 ;
        for(int i=0;i<26;++i){
            if(freq[i] > 0) {
                freq[i]-- ;
                totalCount += 1 + buildChar(freq);
                freq[i]++ ;
            }
        }
        return totalCount ;
    }    
};