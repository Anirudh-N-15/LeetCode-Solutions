class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> count;
        int maxVowel =0, maxCons = 0;

        for(const char &c : s){
            count[c]++ ;
        }

        for(auto it : count){
            if(it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u') {
                maxVowel = max(maxVowel,it.second);
            } else {
                maxCons = max(maxCons,it.second);
            }
        }

        return maxVowel + maxCons ;
    }
};