class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<double> avg;

        int i=0,j = nums.size() - 1;
        while(i < j) {
            double sum = nums[i] + nums[j];
            avg.push_back(sum/2);
            i++ ;
            j-- ;
        }

        return * min_element(avg.begin(),avg.end());
    }
};