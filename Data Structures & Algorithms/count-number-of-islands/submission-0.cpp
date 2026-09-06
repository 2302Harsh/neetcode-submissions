class Solution {
    int directions[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int island=0;

        for(int row =0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col]=='1'){
                    bfs(row,col,grid);
                    island++;
                }
            }
        }

        return island;
    }

private:
    void bfs(int r, int c, vector<vector<char>>& grid){
        queue<pair<int,int>> visited;
        grid[r][c] = '0';
        visited.push({r,c});

        while(!visited.empty()){
            int row = visited.front().first;
            int col = visited.front().second;
            visited.pop();

            for(int i=0; i<4; i++){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];

                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]=='1'){
                    visited.push({nr,nc});
                    grid[nr][nc]='0';
                }
            }
        }
    }
};
