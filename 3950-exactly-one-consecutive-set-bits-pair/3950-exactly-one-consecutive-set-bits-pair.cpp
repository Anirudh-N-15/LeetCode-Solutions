class Solution {
public:
    bool consecutiveSetBits(int n) {
        string binary = "" ;
        while(n > 0) {
            binary += (n % 2 == 0) ? '0' : '1' ;
            n /= 2;
        }
        reverse(binary.begin(),binary.end());
        int size = binary.size() ;

        int flag = 0 ;
        cout << binary << endl ;
        for(int i=0; i < size -1; i++) {
            if(binary[i] == '1' && binary[i+1] == '1') {
                flag++ ;
            }
        }
        
        return flag == 1 ? true : false ;

        
    }
};