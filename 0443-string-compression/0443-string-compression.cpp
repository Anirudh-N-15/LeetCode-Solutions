class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int n = chars.size();
        for(int i=0;i<n;) {
            int count = 0;
            char ch = chars[i];

            while(i < n && chars[i] == ch) {
                count++ ;
                i++ ;
            }
            string num = to_string(count);

            if(count == 1) {
                chars[index] = ch ;
                index++ ;
            } else {
                chars[index] = ch ;
                index++ ;

                for(const char &dig : num) {
                    chars[index] = dig ;
                    index++ ;
                } 
            }
            
        }
        return index;
    }
};