/*
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == '1'){
                    islands++;
                    dfs(grid, r, c, rows, cols);
                }
            }
        }
        return islands;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c, int rows, int cols){

        if(r < 0 || r >= rows || c < 0 || c >= cols){
            return;
        }

        if(grid[r][c] == '0'){
            return;
        }

        grid[r][c] = '0';

        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
    }
};
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int numIslands = 0;

        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == '1'){
                    numIslands++;
                    q.push({r, c});
                    grid[r][c] = '0';

                    while(!q.empty()){
                        auto [row, col] = q.front();
                        q.pop();

                        for(auto [dr, dc] : directions){
                            int newRow = row + dr;
                            int newCol = col + dc;

                            if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || (grid[newRow][newCol] == '0')){
                                continue;
                            }

                            grid[newRow][newCol] = '0';
                            q.push({newRow, newCol});
                        }
                    }
                }
            }
        }
        return numIslands;
    }
};



