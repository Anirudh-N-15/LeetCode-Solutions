class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        unordered_map<char,int> umap;

        for(const char &c : s) {
            umap[c]++ ;
        }
        int oddMax = 1, evenMin = n;

        for(const auto &freq : umap) {
            if(freq.second % 2 != 0) {
                oddMax = max(oddMax,freq.second);
            } else {
                evenMin = min(evenMin,freq.second);
            }
        }
        return oddMax - evenMin ;

    }
};