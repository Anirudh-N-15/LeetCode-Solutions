class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size(),i=0;
        int vert = 0, horz = 0,ans = 0;

        for(const char &c : s){
            if(c == 'N') vert++ ;
            else if(c == 'S') vert-- ;
            else if(c == 'E') horz++ ;
            else horz-- ;

            ans = max(ans,min(abs(vert) + abs(horz) + k*2, i+1));
            i++ ;
        }
        return ans ;
    }
};