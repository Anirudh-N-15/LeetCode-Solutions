class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> power(32);
        for(int i=0;i<32;i++) {
            long long num = pow(2,i);
            power[i] = to_string(num);
        }

        for(int i=0;i<32;++i) {
            sort(power[i].begin(),power[i].end());
        }

        string num = to_string(n);
        sort(num.begin(),num.end());

        for(int i=0;i<32;++i){
            
            if(num == power[i]) {
                return true ;
            }
        }
        return false ;
    }
};