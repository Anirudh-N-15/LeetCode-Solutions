class Solution {
public:
    int findPeakIndex(vector<int>& nums) {
        int n = nums.size() ;
        int left = 0, right = n -1;

        while(left < right) {
            int mid = left + (right - left)/2 ;

            if(nums[mid] < nums[mid+1]) {
                left = mid+1 ;
            } else {
                right = mid ;
            }
        }
        return left ;
    }

    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size() ;

        int index = findPeakIndex(nums);

        long long ascSum = 0, descSum = 0;

        for(int i=0;i<=index;i++) {
            ascSum += nums[i] ;
        }
        for(int i=index; i<n;i++) {
            descSum += nums[i] ;
        }

        if(ascSum == descSum) return -1;

        return ascSum > descSum ? 0 : 1 ;
    }
};