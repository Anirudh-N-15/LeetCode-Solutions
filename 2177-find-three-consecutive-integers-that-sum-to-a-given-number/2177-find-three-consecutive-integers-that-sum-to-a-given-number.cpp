class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long double buffer = num ;
        buffer = buffer/3 ;

        vector<long long> ans(3);

        ans[0] = buffer - 1;
        ans[1] = buffer ;
        ans[2] = buffer + 1;

        if(ans[0]+ans[1]+ans[2] == num){
            return ans ;
        }
        return {} ;

    }
};