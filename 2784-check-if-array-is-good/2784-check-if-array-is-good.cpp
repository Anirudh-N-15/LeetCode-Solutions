class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() ;
        unordered_set<int> st ;
        int count = 0 ;

        for(const int &num : nums) {
            if(num > n -1) return false ;
            if(num == n -1) {
                count++ ;
            }
            st.insert(num);
        }
        return (st.size() == n - 1) && (count == 2) ;
    }
};