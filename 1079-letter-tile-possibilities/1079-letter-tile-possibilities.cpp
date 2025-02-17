class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> freq;
        for(const char &c : tiles) {
            freq[c]++ ;
        }
        int count = 0;
        backtrack(freq,count);
        return count ;
    }
private:
    void backtrack(unordered_map<char,int> tiles,int &count) {
        for(auto [ch,f] : tiles) {
            if(f == 0) continue ;
            count++ ;
            tiles[ch]-- ;
            backtrack(tiles,count);
            tiles[ch]++ ;
        }
    }    
};