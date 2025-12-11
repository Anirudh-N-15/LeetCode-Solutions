class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int size = buildings.size();
        unordered_map<int,int> minX,maxX ;
        unordered_map<int,int> minY,maxY ;

        for(const auto &b : buildings) {
            int x = b[0], y = b[1] ;

            if(!minY.count(x)) {
                minY[x] = maxY[x] = y;
            } else {
                minY[x] = min(y,minY[x]);
                maxY[x] = max(y,maxY[x]);
            }

            if(!minX.count(y)) {
                minX[y] = maxX[y] = x ;
            } else {
                minX[y] = min(x,minX[y]);
                maxX[y] = max(x,maxX[y]);
            }
        }

        int count = 0;

        for(const auto &b : buildings) {
            int x = b[0], y = b[1] ;

            bool coveredX = (minX[y] < x && x < maxX[y]) ;
            bool coveredY = (minY[x] < y && y < maxY[x]) ;

            if(coveredX && coveredY) {
                count++ ;
            }
        }
        return count ;
        
    }
};