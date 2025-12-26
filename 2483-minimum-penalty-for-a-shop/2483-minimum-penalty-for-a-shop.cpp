class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penalty = 0;

        for(const char &ch : customers) {
            if(ch == 'Y') penalty++ ;
        }
        if(penalty == n) return n ;

        int minPenalty = penalty ;
        int index = 0;

        for(int i=1;i<n;i++) {
            if(customers[i-1] == 'N') {
                penalty++ ;
            } else {
                penalty-- ;
            }

            if(penalty < minPenalty) {
                minPenalty = penalty ;
                index = i ;
            }
        }
        return index ;
    }
};