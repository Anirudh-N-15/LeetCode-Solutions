class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map <int,int> mp ;
        vector <int> ans ;

        for(int num : nums){
            mp[num]++ ;
        }

        for(int num : nums){
            if( mp[num] == 2){
                ans.push_back(num);
            }
            mp[num] = 0;
        }
        return ans ;
    }
};