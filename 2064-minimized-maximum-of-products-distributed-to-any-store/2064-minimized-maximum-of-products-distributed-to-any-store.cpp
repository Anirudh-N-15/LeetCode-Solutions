class Solution {
public:
    int canDis( vector<int>& nums, int &mid, int& n) {
        int stores = 0;
        for(const int &num : nums) {
            stores += num/mid ;
            if(num % mid) stores++ ;
            if(stores > n) return 0 ;
        }
        return stores <= n ;
    }

    int minimizedMaximum(int n, vector<int>& nums) {
        int start = 1, end = *max_element(nums.begin(),nums.end());

        while(start <= end) {
            int mid = start + (end - start)/ 2;

            if(canDis(nums,mid,n)) {
                end = mid - 1;
            } else {
                start = mid  + 1;
            }
        }
        return start ;
    }
};