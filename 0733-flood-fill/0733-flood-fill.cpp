class Solution {
  public:
    void bfs(vector<vector<int>>& image, int sr, int sc,int newColor,vector<vector<bool>>& visited,int currColor) {
        int n = image.size(), m = image[0].size() ;
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        
        visited[sr][sc] = 1;
        image[sr][sc] = newColor;
        q.push({sr,sc});
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            
            for(auto it : dir) {
                int nrow = node.first + it.first ;
                int ncol = node.second + it.second ;
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if(!visited[nrow][ncol] && image[nrow][ncol] == currColor) {
                        visited[nrow][ncol] = 1;
                        image[nrow][ncol] = newColor ;
                        q.push({nrow,ncol});
                    } 
                }  
                
            }
        }
    
    }
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newColor){
        int n = image.size(), m = image[0].size() ;
        int currColor = image[sr][sc] ; 
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        bfs(image,sr,sc,newColor,visited,currColor);
        return image ;
    }
};