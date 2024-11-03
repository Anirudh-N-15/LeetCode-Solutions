class Solution {
public:
    bool isBalanced(string num) {
        int oddsum = 0,evensum=0;
        for(int i=0;i<num.size();i += 2){
            evensum += num[i] - '0' ;
        }

        for(int i=1;i<num.size();i += 2){
            oddsum += num[i] - '0' ;
        }

        return oddsum == evensum ? 1 : 0 ;
    }
};