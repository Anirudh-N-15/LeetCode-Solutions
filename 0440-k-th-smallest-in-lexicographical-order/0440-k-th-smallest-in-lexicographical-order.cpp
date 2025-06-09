class Solution {
public:
    int countNode(long num, long nextNum, int n) {
        int count = 0;

        while(num <= n) {
            count += (nextNum - num);

            num *= 10, nextNum *= 10;

            nextNum = min(nextNum, (long)n+1);
        }
        return count ;
    }

    int findKthNumber(int n, int k) {
        int num = 1;
        k-- ;

        while(k > 0) {
            int count = countNode(num,num+1,n);

            if(count <= k) {
                num++ ;
                k -= count ; //Skipped elements under this prefix tree
            } else {
                num *= 10 ; //Present in this prefix tree
                k -= 1;
            }
        }
        return num ;
    }
};