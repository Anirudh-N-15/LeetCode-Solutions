class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n -1;

        while(left < right) {
            int mid = (left + right)/2 ;

            if(arr[mid] > arr[mid -1] && arr[mid] > arr[mid + 1]) {
                return mid ;
            }

            else if(arr[mid -1] > arr[mid]){
                right = mid ;
            } else {
                left = mid ;
            }
        }
        return -1 ;
    }
};