//If we don't initialise with INT_MAX we can directly avoid the if condtion
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int> (n,1e9)) ;
        int count =0;

        //Kind of constructing the adj matrix
        for(auto &edge : edges){
            int u = edge[0], v = edge[1],w= edge[2] ;
            dp[u][v] = w ;
            dp[v][u] = w ;
        }

        //Making sure there are no self loops
        for(int i=0;i<n;++i){
            dp[i][i] = 0 ;
        }

        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        int minreachablecity = n ;
        int result = -1 ;


        for(int i=0;i<n;++i){
            int resultcount = 0 ;

            for(int j=0;j<n;++j){
                if(i!=j && dp[i][j] <= distanceThreshold){
                    resultcount++ ;
                }
            }

            //Because we have to return the city with the greatest number
            //Even afer finding the city with the minimum number
            if(resultcount <= minreachablecity){
                minreachablecity = resultcount ;
                result = i ;
            }
        }
        return result ;
    }
};