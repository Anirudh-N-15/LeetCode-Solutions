class Solution {
public:
    pair<int, int> getCoordinates(int cellNumber, int boardSize) {
        int colIndex = (cellNumber - 1) % boardSize;
        int rowIndex = (cellNumber - 1) / boardSize;
        int actualCol;
        if (rowIndex % 2 == 0) {
            actualCol = colIndex;
        } else {
            actualCol = boardSize - colIndex - 1;
        }
        return make_pair(boardSize - rowIndex - 1, actualCol);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int boardSize = board.size();
        vector<bool> visited(boardSize * boardSize + 1, false);

        queue<pair<int, int>> q;
        q.push(make_pair(1, 0)); 
        visited[1] = true;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int cellNum = curr.first;
            int moveCount = curr.second;

            if (cellNum == boardSize * boardSize)
                return moveCount;

            for (int diceRoll = 1; diceRoll <= 6; diceRoll++) {
                int nextCell = cellNum + diceRoll;
                if (nextCell > boardSize * boardSize)
                    break;

                pair<int, int> coordinates = getCoordinates(nextCell, boardSize);
                int row = coordinates.first;
                int col = coordinates.second;

                int destination = board[row][col] == -1 ? nextCell : board[row][col];
                if (!visited[destination]) {
                    q.push(make_pair(destination, moveCount + 1));
                    visited[destination] = true;
                }
            }
        }

        return -1;
    }
};