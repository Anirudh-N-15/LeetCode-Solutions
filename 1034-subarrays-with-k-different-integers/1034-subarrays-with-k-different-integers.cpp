//So the intuition here is to find all subarrays of window size k and k-1.
//The required answer is the count of subarrays of (size k) - (size k-1).
//The proof consists of set theory and inclusion exclusion principle.
//Basically to get k different integers as subarrays we can just find the 
//number of subarrays with at most k distinct and subtract that with at most
//k-1 distinct integers to give us exactly k disctinct integers.

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> umap1, umap2 ;
        int left = 0,count1 = 0,count2 = 0;

        //This loop will calculate for us the number of subarrays with at most k
        //distinct integers.
        for(int right=0;right<n;right++) {
            umap1[nums[right]]++ ;

            while(umap1.size() > k) {
                umap1[nums[left]]-- ;
                if(umap1[nums[left]] == 0) {
                    umap1.erase(nums[left]);
                }
                left++ ;
            }
            count1 += right - left + 1;
        }
        left = 0;

        for(int right=0;right<n;right++) {
            umap2[nums[right]]++ ;

            while(umap2.size() > k-1) {
                umap2[nums[left]]-- ;
                if(umap2[nums[left]] == 0) {
                    umap2.erase(nums[left]);
                }
                left++ ;
            }
            count2 += right - left + 1;
        }
        return count1 - count2 ;
    }
};