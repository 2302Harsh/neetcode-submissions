class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> toVisit;

        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j]==0) toVisit.push({i,j});
            }
        }

        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!toVisit.empty()){
            int row = toVisit.front().first;
            int col = toVisit.front().second;
            toVisit.pop();

            for(int i=0; i<4; i++){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];

                if(nc<0 || nr<0 || nc>=m || nr>=n || grid[nr][nc] != INT_MAX) continue;

                grid[nr][nc] = grid[row][col]+1;
                toVisit.push({nr,nc});
            }
        }
    }
};
