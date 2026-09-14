class Solution {
    int directions[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int island =0;

        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j);
                    island++;
                }
            }
        }

        return island;
    }

private:
    void bfs(vector<vector<char>>& grid, int r, int c){
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = '0';

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto dir : directions){
                int nr = row + dir[0];
                int nc = col + dir[1];

                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc] == '1'){
                    q.push({nr,nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
