class Solution {
public:
    int maxDistinct(string s) {
        vector<int> freq(26,0);

        for(const char &ch : s) {
            freq[ch - 'a']++ ;
        }

        int count = 0;
        for(const int &num : freq) {
            if(num > 0) {
                count++ ;
            }
        }
        return count ;
    }
};