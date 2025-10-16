class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int,int> freq ;
        for(int i=0;i<n;i++) {
            nums[i] = ((nums[i] % value) + value) % value  ;
            freq[nums[i]]++ ;
        }

        for (int i = 0; ; i++) {
            int rem = i % value;
            if (freq[rem] == 0) return i;
            freq[rem]--;
        }
    }
};