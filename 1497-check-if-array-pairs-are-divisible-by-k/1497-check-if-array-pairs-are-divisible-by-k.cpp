class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map <int,int> mp ;

        for(int num : arr){
            int remainder = ((num % k)+ k) % k ;

            mp[remainder]++ ;
        }

        for(auto &entry : mp){
            int remainder = entry.first ;
            int count = entry.second ;

            if(remainder == 0){
                if(count % 2 != 0) return false ;
            }    

            else {
                int complement = k - remainder ;
                if(mp[complement] != count) return false ;
            }
            
        }
        return true ;
    }
};