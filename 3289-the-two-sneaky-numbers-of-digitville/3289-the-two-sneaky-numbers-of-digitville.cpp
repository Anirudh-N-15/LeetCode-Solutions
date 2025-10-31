class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> freq(101,0);
        vector<int> ans;

        for(const int &num : nums) {
            freq[num]++ ;
        }
        for(int i=0;i<101;i++) {
            if(freq[i] == 2) {
                ans.push_back(i);
            }
        }
        return ans ;
    }
};