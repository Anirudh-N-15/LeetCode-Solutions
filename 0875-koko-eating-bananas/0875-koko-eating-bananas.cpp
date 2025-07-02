class Solution {
public:
    int check(vector<int>& piles,int &num) {
        int hours = 0;

        for(const int &pile : piles) {
            if(pile % num == 0) {
                hours += pile/num ;
            } else {
                hours += (pile/num) + 1;
            }
        }
        return hours ;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int greatest = *max_element(piles.begin(),piles.end());
        int start = 1, end = greatest ;

        while(start <= end) {
            int mid = start + (end - start)/2 ;

            cout << mid << " " ;

            if(check(piles,mid) <= h) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start ;
    }
};