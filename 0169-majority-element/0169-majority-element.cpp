class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = -1, votes =0,count =0;

        for(int &num : nums){
            if(votes == 0){
                candidate = num;
                votes = 1;
            } else if(num == candidate){
                votes++ ;
            } else {
                votes-- ;
            }
        }

        for(int &num : nums){
            if(num == candidate){
                count++ ;
            }
            if(count > n/2){
                return candidate;
            }
        }
        return -1; 
    }
};