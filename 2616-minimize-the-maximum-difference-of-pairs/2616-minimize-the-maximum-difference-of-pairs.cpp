class Solution {
public:
    int countValidPairs(vector<int>& nums, int mid) {
        int count = 0, i=0,n = nums.size();
        while(i < n -1) {
            if(nums[i + 1] - nums[i] <= mid) {
                count++ ;
                i++ ;
            }
            i++ ;
        }
        return count ;
    }


    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0, right = nums[n-1] - nums[0];

        while(left < right) {
            int mid = left + (right - left)/2 ;

            if(countValidPairs(nums,mid) >= p) {
                right = mid ;
            } else {
                left = mid +1 ;
            }
        }
        return left ;
    }
};