class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int ptr1 = 0, ptr2 = 1;
        int n = bits.size();

        while(ptr1 < n) {
            if(bits[ptr1] == 1 && ptr2 == n -1) {
                return false ;
            }
            if(ptr2 >= n) {
                return true ;
            }
            if(ptr2 < n && bits[ptr1] == 1 && (bits[ptr2] == 0 || bits[ptr2] == 1)) {
                ptr1 += 2;
                ptr2 += 2;
            }
            if(bits[ptr1] == 0) {
                ptr1++ ;
                ptr2++ ;
            }
        }
        return true ;
    }
};