class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0, curr = 0;
        if(digits[n-1] + 1 < 10) {
            digits[n-1]++ ;
            return digits; 
        }

        if (digits[n-1] + 1 >= 10) {
            carry = (digits[n-1] + 1) / 10;
            digits[n-1] = ((digits[n-1] + 1) % 10);
        }

        for(int i=n-2;i>=0;i--) {
            if(digits[i] + carry >= 10) {
                carry = (digits[i] + carry) / 10;
                digits[i] = ((digits[i] + carry) % 10);
            } else {
                digits[i] += carry ;
                carry = 0;
            }
        }

        if(carry != 0) digits.insert(digits.begin(),carry);

        return digits ;
    }
};