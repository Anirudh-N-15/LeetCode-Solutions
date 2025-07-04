//This question is similar to all other Binary Search question but needs a 
//small tweaking as it also has a bit of greedy approach involved.

class Solution {
public:
    bool canPlace(vector<int>& position, int dist,int m) {
        //last is initialised with index 0 because we are greedily placing the first ball
        //at index 0.
        int n = position.size();
        int last = position[0], ballCount = 1 ;

        for(int i=1;i<n;i++) {
            //If the calculated dist is greater than our current dist then we should
            //definetly place the ball there.
            if(position[i] - last >= dist) {
                ballCount++ ;
                last = position[i] ;
            } 
            if(ballCount >= m) {
                return true ;
            }
        }
        return false ; //We were unable to place all the balls hence we need to 
                       //minimise the distance.
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int start = 1, end = position[n-1] - position[0] ;

        while(start <= end) {
            int mid = start + (end - start)/2 ;

            if(canPlace(position,mid,m)) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end ; //Because this will point to the minimum after search ends
    }
};