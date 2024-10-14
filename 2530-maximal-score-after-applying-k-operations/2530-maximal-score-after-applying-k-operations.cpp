class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());

        double max = 0;
        long long result=0 ;

        for(int i=0;i<k;++i){
            pop_heap(nums.begin(),nums.end());
            max = nums[nums.size()-1];
            nums.pop_back();
            result += max ;
            max = ceil((double)max/3) ;
            nums.push_back(max);
            push_heap(nums.begin(),nums.end());
        }
        
        return result ;
    }
};