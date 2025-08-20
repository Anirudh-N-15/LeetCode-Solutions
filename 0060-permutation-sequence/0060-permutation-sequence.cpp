//An observation here is to find the number of permutations needed for numbers
//after the first digit is fixed. That is first we have to find which block the 
//number belongs to i.e if there are total 3 numbers after the first number then
//we have to do ((k-1)/3!) {k-1 since we go for 0 based indexing}.
//And ((k-1) % 3!) which will give which number of sequence from the lexicographical
//sorted number is the permuation we require.

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;
        k-- ;
        for(int i=1;i<n;i++) {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);

        string ans = "";

        while(1) {
            ans += to_string(nums[k/fact]); 
            nums.erase(nums.begin() + k/fact);
            if(nums.size() == 0) break ;

            k = k % fact ;
            fact = fact/nums.size();
        }  
        return ans ;
    }
};