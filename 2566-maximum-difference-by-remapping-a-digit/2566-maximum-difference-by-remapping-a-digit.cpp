class Solution {
public:
    int minMaxDifference(int num) {
        string maxi = to_string(num);
        string mini = to_string(num);
        int n = maxi.size();

        char first ;
        char second ;
        
        for(const char &ch : maxi) {
            if(ch != '0') {
                second = ch ;
                break;
            }
        }

        for(const char &ch : maxi) {
            if(ch != '9') {
                first = ch ;
                break;
            }
        }

        for(int i=0;i<n;i++) {
            if(maxi[i] == first) {
                maxi[i] = '9' ;
            }
            if(second == mini[i]) {
                mini[i] = '0' ;
            }
        }

        int max = stoi(maxi);
        int min = stoi(mini);
        return max - min ;
    }
};