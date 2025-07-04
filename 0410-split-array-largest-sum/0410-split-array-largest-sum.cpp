class Solution {
public:
    int split(vector<int>& nums, int possible) {
        int currSum = 0, splitNum = 1;

        for(const int &num : nums) {
            if(currSum + num <= possible) {
                currSum += num ;
            } else {
                currSum = num ;
                splitNum++ ;
            }
        }
        return splitNum ;
    }

    int splitArray(vector<int>& nums, int k) {
        int start = 0, end = 0;
        for(const int &num : nums) {
            start = max(start,num);
            end += num ;
        }

        while(start <= end) {
            int mid = start + (end - start)/2 ;
            cout << mid << " " ;

            if(split(nums,mid) <= k) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start ;
    }
};