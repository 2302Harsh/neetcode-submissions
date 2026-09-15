class Solution {
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for(int i =0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int area = bfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

private:
    int bfs(vector<vector<int>>& grid, int r, int c ){
        queue <pair<int,int>> q;
        q.push({r,c}); 
        grid[r][c] = 0;
        int area =1;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto dir : directions){
                int nr = row + dir[0];
                int nc = col + dir[1];

                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc] == 1){
                    grid[nr][nc] = 0;
                    q.push({nr,nc});
                    area++;
                }
            }
        }

        return area;
    }
    
};
