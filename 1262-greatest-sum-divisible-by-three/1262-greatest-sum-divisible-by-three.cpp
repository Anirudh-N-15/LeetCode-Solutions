class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> umap ;
        sort(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0);

        for(int &num : nums) {  
            umap[num % 3].push_back(num);
        }

        if(sum % 3 == 0) return sum ;
        
        else if(sum % 3 == 1) {
            int ans = INT_MAX ;
            int num = INT_MAX ;
            
            if(umap[1].size() >= 1) {
                ans = umap[1][0] ;
            } 
            if(umap[2].size() >= 2) {
                num = umap[2][0] + umap[2][1] ;
            }
            int rem = min(ans,num);
            if(rem == INT_MAX) return 0;
            sum -= min(ans,num);
            
        } 

        else {
            int ans = INT_MAX ;
            int num = INT_MAX ;
            if(umap[2].size() >= 1) {
                ans = umap[2][0] ;
            } 
            if(umap[1].size() >= 2) {
                num = umap[1][0] + umap[1][1] ;
            }
            int rem = min(ans,num);
            if(rem == INT_MAX) return 0;
            sum -= min(ans,num);
        }
        return sum ;
    }
};