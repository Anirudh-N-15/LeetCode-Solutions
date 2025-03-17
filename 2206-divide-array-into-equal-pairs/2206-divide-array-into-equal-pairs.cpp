class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(501,0);

        for(int i=0;i<n;++i){
            count[nums[i]]++ ;
        }
        n = count.size();

        for(int i=0;i<n;++i){
            if(count[i] % 2 != 0){
                return false ;
            }
        }
        return true ;
    }
};