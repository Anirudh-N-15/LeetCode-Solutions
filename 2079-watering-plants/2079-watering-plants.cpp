class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int steps = 0;
        int curr = capacity ;

        for(int i=0;i<n;i++) {
            if(curr >= plants[i]) {
                steps++ ;
                curr -= plants[i] ;
            } else {
                steps += i;
                curr = capacity ;
                steps += i+1 ;
                curr -= plants[i] ;
            }
        }
        return steps;
    }
};