class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> result(2,-1);

        if(nums.size()==0)
        return result ;

        int start =0,end = nums.size()-1,mid;
        
        while(start<=end)
        {
            mid = start+ (end-start)/2 ;

            if(nums[mid]==target)
            {
               result[0]=mid;
               result[1]=mid;
                end = mid-1;
            }

            else if(nums[mid]<target)
            {
                start = mid+1 ;
            }
            else
            {
                end = mid-1 ;
            }
        }

        start =mid,end = nums.size()-1 ;
        while(start<=end)
        {
            mid = (start+end)/2 ;

            if(nums[mid]==target)
            {
                result[1]=mid;
                start = mid+1;
                printf("no");
            }

            else if(nums[mid]<target)
            {
                start = mid+1;
            }
            else
            end = mid-1 ;
        }

        return result ;
    }
};