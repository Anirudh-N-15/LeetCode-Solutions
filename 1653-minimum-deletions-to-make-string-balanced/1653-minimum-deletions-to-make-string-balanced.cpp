//So the idea here is that whenever we encounter a character 'b' then we increment the 
//counter.While the counter is not zero and we encounter char 'a' then we  decrement
//the counter whilst increasing our answer because that is the number of a's we have
//to remove that occurs after b. 

class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, count = 0;

        for(const char &c : s) {
            if(c == 'b') {
                count++ ;
            } else if(count) {
                count-- ;
                ans++ ;
            }
        }
        return ans ;
    }
};