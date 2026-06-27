class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> freq ;

        for(const int &num : nums) {
            freq[num]++ ;
        }

        int ans = 1;

        if(freq.count(1)) ans = (freq[1] % 2) ? freq[1] : freq[1] -1 ;

        int mx = *max_element(nums.begin(),nums.end());

        for( auto &[elem,cnt] : freq) {
            if(elem == 1) continue ;
            int len = 0 ;

            long long x = elem ;
            while (x <= mx) {
                auto it = freq.find(x);
                if (it == freq.end() || it->second < 2)
                    break;

                len += 2;
                x = x * x;
            }
            
            if(freq.count(x)) {
                len++ ;
            } else {
                len-- ; 
            }

            ans = max(ans,len);
        }

        return ans ;
    }
};