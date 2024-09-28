class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0,right = nums.size()-1 ;
        if(nums.size()==1){
            return nums[0] ;
        }
        if(nums[right] > nums[0]){
            return nums[0] ;
        }

        while(left <= right){
            int mid = (left + right)/2 ;

            if(mid  < nums.size()-1 && nums[mid+1] < nums[mid]){
                return nums[mid +1] ;
            }   

            if(mid > 0 &&  nums[mid] < nums[mid -1]){
                return nums[mid];
            }

            else if( nums[mid] < nums[right]){
                right = mid - 1;
            }

            else{
                left = mid + 1; 
            }

        }
            return -1 ;
    }
};