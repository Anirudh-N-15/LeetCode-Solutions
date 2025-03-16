class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> uset;

        if( *max_element(nums.begin(),nums.end()) < 0){
            return *max_element(nums.begin(),nums.end());
        }

        for(int num : nums){
            if(uset.find(num) == uset.end()){
                uset.insert(num);
            }
        }

        vector<int> maxim ;

        for(auto elem : uset){
            maxim.push_back(elem);
        }

        int sum = 0;

        for(int i=0;i<maxim.size();++i){
            if(maxim[i] > 0){
                sum += maxim[i];
            }
        }
        return sum ;
    }
};