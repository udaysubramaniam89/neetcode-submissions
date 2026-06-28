class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        
        queue<pair<int, int>> q;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 2){
                    q.push({r, c});
                }

                else if(grid[r][c] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0){
            return 0;
        }

        int minutes = 0;

        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}           
        };

        while(!q.empty() && fresh > 0){
            int size = q.size();

            for(int i = 0; i < size; i++){
                auto [row, col] = q.front();
                q.pop();

                for(auto [dr, dc] : directions){
                    int newRow = dr + row;
                    int newCol = dc + col;

                    if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || grid[newRow][newCol] != 1){
                        continue;
                    }

                    grid[newRow][newCol] = 2;
                    fresh--;
                    q.push({newRow, newCol});
                }
            }
            minutes++;
        }
        if(fresh == 0){
            return minutes;
        }

        return -1;
    }
};
