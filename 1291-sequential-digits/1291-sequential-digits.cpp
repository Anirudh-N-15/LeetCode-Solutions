class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789" ;
        vector<int> ans ;

        for(int i = 0; i < num.size(); i++) {
            string number = "" ;
            for(int j = i; j < num.size(); j++) {
                number += num[j] ;
                long long inter = stoll(number) ;

                if( inter >= low && inter <= high) {
                    ans.push_back(inter) ;
                }
            }
        }
        sort(ans.begin(),ans.end()) ;
        return ans ;
    }
};