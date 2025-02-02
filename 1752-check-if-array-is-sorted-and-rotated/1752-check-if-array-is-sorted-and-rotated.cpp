class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int>copy;
        copy = nums;
        sort(copy.begin(),copy.end());
        vector<int> twice;
        twice = copy;
        
        for(int i=0;i<n;++i){
            twice.push_back(copy[i]);
        }

        for(int i=0;i<n;++i){
            int count =0;
            for(int j=0;j<n;++j){
                if(nums[j] == twice[i+j]){
                    count++ ;
                }
            }
            if(count == n){
                return true ;
            }
        }
        return false; 
    }
};