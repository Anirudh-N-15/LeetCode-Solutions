class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        unordered_map<int,int> mp;

        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                mp[nums[i]*nums[j]]++ ;
            }
        }

        for(auto it :mp){
            count += (4 * it.second * (it.second -1));
        }
        return count ;
    }
};