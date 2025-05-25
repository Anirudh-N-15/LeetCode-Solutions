class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789" ;
        vector<int> res;
        
        for(int i = 0;i<num.size();++i) {
            string s = "" ;
            for(int j=i;j<num.size();++j) {
                s += num[j] ;
                int number = stoll(s);
                if(number >= low && number <= high) {
                    res.push_back(number);
                }   
            }
        }
        sort(res.begin(),res.end());
        return res ;
    }
};