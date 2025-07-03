class Solution {
public:
    int possible(vector<int>& bloomDay, int m, int k,int day) {
        int n = bloomDay.size();
        int boquets = 0;
        int count = 0;

        for(int i=0;i<n;i++) {
            if(bloomDay[i] <= day) {
                count++ ;
            } else {
                boquets += (count/k) ;
                count = 0;
            }
        }
        boquets += (count/k) ;

        if(boquets >= m) return true ;

        return false ;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long )m*k > n) return -1;

        int mini = *min_element(bloomDay.begin(),bloomDay.end());
        int maxi = *max_element(bloomDay.begin(),bloomDay.end());

        while(mini <= maxi) {
            int mid = mini + (maxi - mini)/2 ;

            if(possible(bloomDay,m,k,mid)) {
                maxi = mid - 1;
            } else {
                mini = mid + 1;
            }
        }
        return mini ;
    }
};