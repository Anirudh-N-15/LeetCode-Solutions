class Solution {
public:
    int hammingWeight(int n) {
        int num = n;
        int count = 0;
        while(num > 0){
            if(num % 2 !=0){
                count++ ;
            }
           num = (num >> 1);
        }
        return count ;
    }
};