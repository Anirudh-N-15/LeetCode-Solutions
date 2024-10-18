class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max=0;
        for(int num:nums){
            max|=num;
        }
        int count=0;

        backtrack(nums,max,0,0,count);

        return count ;
    }

    void backtrack(vector<int> nums,int max,int current,int index,int &count){
        if(current == max){
        count+= 1<<nums.size()-index;
        return;
        }

        for(int i=index;i<nums.size();++i){
            backtrack(nums,max,current | nums[i],i+1,count);
        }
    }
};