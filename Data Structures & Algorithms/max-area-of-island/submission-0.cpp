class Solution {
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        int maxArea =0;

        for(int r=0; r<ROW; r++){
            for(int c=0; c<COL; c++){
                if(grid[r][c]==1){
                    maxArea = max(maxArea, bfs(r,c,grid));
                }
            }
        }
        return maxArea;
    }

private:
    int bfs(int r, int c, vector<vector<int>>& grid){
        queue<pair<int,int>> visited;
        grid[r][c]=0;
        visited.push({r,c});
        int area=1;

        while(!visited.empty()){
            int row = visited.front().first;
            int col = visited.front().second;
            visited.pop();

            for(int i=0; i<4; i++){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if(nr>=0 && nc>=0 && nc< grid[0].size() && nr<grid.size() && grid[nr][nc]==1){
                    area++;
                    visited.push({nr,nc});
                    grid[nr][nc]=0;
                }
            }
        }

        return area;
    }
};
