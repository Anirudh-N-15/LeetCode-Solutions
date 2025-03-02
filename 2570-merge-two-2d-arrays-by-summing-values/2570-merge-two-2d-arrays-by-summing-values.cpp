class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans ;
        int i = 0,j=0;
        while(i < n && j < m){
            if(nums1[i][0] > nums2[j][0]){
                ans.push_back({nums2[j][0],nums2[j][1]});
                j++ ;
            }
            else if(nums1[i][0] < nums2[j][0]){
                ans.push_back({nums1[i][0],nums1[i][1]});
                i++ ;
            }
            else{
                ans.push_back({nums1[i][0],nums1[i][1]+nums2[j][1]});
                i++ ;
                j++ ;
            }
        }

        if(i < n){
            for(;i<n;++i){
                ans.push_back({nums1[i][0],nums1[i][1]});
            }
        } else if(j < m){
            for(;j<m;++j){
                ans.push_back({nums2[j][0],nums2[j][1]});
            }
        }
        return ans;
    }
};