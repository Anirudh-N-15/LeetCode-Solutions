class cell {
public:
    int row;
    int col;
    int value;
    cell(int r, int c, int v) : row(r), col(c), value(v) {}    
};

class query{
public:
    int index;
    int value;
    query(int i, int v) : index(i), value(v) {}
};

class unionFind{
private:    
    vector<int> parent;
    vector<int> size;

public:
    unionFind(int n) : parent(vector<int>(n,-1)), size(vector<int>(n,1)) {}

    int find(int node) {
        if(parent[node] < 0){
            return node;
        }
        return parent[node] = find(parent[node]);
    }   

    bool unionNode(int node1, int node2){
        int root1 = find(node1);
        int root2 = find(node2);

        if(root1 == root2) return false ;

        if (size[root1] > size[root2]){
            parent[root2] = root1;
            size[root1] += size[root2];
        } 
        else{
            parent[root1] = root2;
            size[root2] += size[root1];
        }
        return true;
    }

    int getSize(int node){
        return size[find(node)];
    } 

};


bool operator<(const query& a, const query& b) { return a.value < b.value; }

bool operator<(const cell& a, const cell& b) { return a.value < b.value; }

const vector<int> ROW_DIRECTIONS = {0, 0, 1, -1};
const vector<int> COL_DIRECTIONS = {1, -1, 0, 0};


class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();
        int total = n*m ;

        vector<query> sortedQuery ;
        for(int i=0;i< queries.size();++i){
            sortedQuery.push_back(query(i,queries[i]));
        }
        sort(sortedQuery.begin(), sortedQuery.end());

        vector<cell> sortedCells;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sortedCells.push_back(cell(i, j, grid[i][j]));
            }
        }

        sort(sortedCells.begin(), sortedCells.end());

        unionFind uf = unionFind(total);
        vector<int> result(queries.size());
        int cellIndex = 0;

        for (query query : sortedQuery) {
            while (cellIndex < total && sortedCells[cellIndex].value < query.value) {
                int row = sortedCells[cellIndex].row;
                int col = sortedCells[cellIndex].col;
                int cellId = row * m + col;
            

                for (int direction = 0; direction < 4; direction++) {
                    int newRow = row + ROW_DIRECTIONS[direction];
                    int newCol = col + COL_DIRECTIONS[direction];

                    if (newRow >= 0 && newRow < n && newCol >= 0 
                        &&newCol < m &&grid[newRow]    [newCol] < query.value) {
                    uf.unionNode(cellId, newRow * m + newCol);
                    }
                }
                cellIndex++ ;
            }
            result[query.index] = query.value > grid[0][0] ? uf.getSize(0) : 0;

        }  

        return result ;
    }
};