class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq ;
        unordered_set<int> seen ;

        for(const int & num : arr) {
            freq[num]++ ;
        }

        for(const auto &[key,val] :freq) {
            if(seen.find(val) == seen.end()) {
                seen.insert(val);
            } else {
                return false; 
            }
        }
        return true ;
    }
};