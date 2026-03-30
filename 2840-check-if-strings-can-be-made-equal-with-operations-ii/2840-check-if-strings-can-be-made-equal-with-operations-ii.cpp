class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        unordered_map<int, int> evenMap ,oddMap;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evenMap[s1[i]]++;
            } else {
                oddMap[s1[i]]--;
            }
        }

        for (int i = 0; i < m; i++) {
            if(i % 2 == 0) {
                evenMap[s2[i]]-- ;
            } else {
                oddMap[s2[i]]++ ;
            }
        }

        for(auto [key,val] : evenMap) {
            if(val != 0) {
                return false ;
            }
        }

        for(auto [key,val] : oddMap) {
            if(val != 0) {
                return false ;
            }
        }
        return true ;
    }
};