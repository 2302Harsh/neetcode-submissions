class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;

        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int row  =q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto dir : directions){
                int nr = row + dir[0];
                int nc = col + dir[1];

                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc] == 2147483647){
                    q.push({nr,nc});
                    grid[nr][nc] = grid[row][col] + 1;
                }
            }

        }
    }
};
