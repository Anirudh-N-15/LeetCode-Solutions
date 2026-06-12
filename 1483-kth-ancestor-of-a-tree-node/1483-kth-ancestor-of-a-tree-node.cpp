class TreeAncestor {
public:
    vector<vector<int>> ancestor ;
    int log ;
    TreeAncestor(int n, vector<int>& parent) {
        log = 20;
        ancestor.assign(n,vector<int>(log,-1));

        //Filling the immediate parent of all nodes
        for(int i = 0; i < n; i++) {
            ancestor[i][0] = parent[i] ;
        }

        for(int j = 1; j < log; j++) {
            for( int i = 0; i < n; i++) {
                if(ancestor[i][j-1] != -1) {
                    ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1] ;
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {

        for(int i = 0; i < log; i++) {

            if( k & (1 << i)) {
                node = ancestor[node][i] ;

                if(node == -1) {
                    return -1 ;
                }
            }
        }

        return node ;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
