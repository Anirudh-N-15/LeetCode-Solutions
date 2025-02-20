class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result = "";
        for(int i=0;i<nums.size();++i){
            if(nums[i][i] == '1') result.push_back('0');
            else result.push_back('1');
        }
        return result ;
    }
};