class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long ans = 0;
        vector<int> seen(n);
        set<pair<int,int>> numAndIndex;

        for(int i =0;i<n;++i){
            numAndIndex.insert({nums[i],i});
        }

        for(const auto &[num,i] : numAndIndex){
            if(seen[i]){
                continue;
            }
            if(i>0){
                seen[i-1] = true ;
            }
            if(i+1 < n){
                seen[i+1] = true ;
            }
            seen[i] = true; 
            ans+= num ;
        }
        return ans;
    }
};