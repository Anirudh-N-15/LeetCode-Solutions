class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        unordered_set <int> uset(nums.begin(),nums.end());
        int sum = 0;
        for(int i : nums) {
            sum += i;
        }   
        float avg = sum/(float)n ;
        cout << avg ;
        if(avg < 0) {
            avg = 0;
        }

        for(int i=(int)(avg)+1;i < sum+100000 ; i++) {
            if(uset.find(i) == uset.end()) {
                return i ;
            }
        }
        return -1 ;
    }
};