class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> res ;
        vector<int> ans ;
        int n = digits.size() ;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n;++j) {
                for(int k = 0; k < n; ++k) {
                    int num = (digits[i]*100) + (digits[j]*10) + digits[k] ;
                    if(i == j || j==k || i== k){
                        continue ;
                    }
                    if(num % 2 == 0 && num >= 100){
                        res.insert(num);
                    }
                }
            }
        }
        for(const int &num : res){
            ans.push_back(num);
        }
        sort(ans.begin(),ans.end());
        return ans ;

    }
};