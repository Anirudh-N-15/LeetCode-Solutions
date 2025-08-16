class Solution {
public:
    int maximum69Number (int num) {
        int temp = num, digitCount = 0, rightCount = -1;

        while(temp > 0) {
            int digit = temp % 10;
            if(digit == 6) rightCount = digitCount ;
            digitCount++ ;
            temp /= 10;
        }      
        if(rightCount == -1) return num ;
        num += 3 * pow(10,rightCount) ;
        return num ;
    }
};