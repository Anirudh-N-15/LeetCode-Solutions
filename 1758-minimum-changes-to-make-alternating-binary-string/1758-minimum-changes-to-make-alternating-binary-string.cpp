class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string start0 = "0", start1 = "1";

        for(int i=1;i<n;i++) {
            if(i % 2 != 0) {
                start0.push_back('1');
                start1.push_back('0');
            } else {
                start0.push_back('0');
                start1.push_back('1');
            }
        }
        
        int count1 = 0, count2 = 0;

        for(int i=0;i<n;i++) {
            if(start0[i] != s[i]) {
                count1++ ;
            } 
            if(start1[i] != s[i]) {
                count2++ ;
            }
        }
        return min(count1,count2) ;

    }
};