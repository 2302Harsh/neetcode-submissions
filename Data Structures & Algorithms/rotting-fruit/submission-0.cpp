class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size();
        int m = grid[0].size();
        int fresh =0;
        int min =0;

        queue<pair<int,int>> toVisit;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) toVisit.push({i,j});
            }
        }

        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
 
        while(fresh>0 && !toVisit.empty()){
            int len = toVisit.size();
            for(int i=0; i<len; i++){
                int row = toVisit.front().first;
                int col = toVisit.front().second;
                toVisit.pop();

                for(int i=0; i<4; i++){
                    int nr = row + directions[i][0];
                    int nc = col + directions[i][1];

                    if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]== 1) {
                        grid[nr][nc]=2;
                        fresh--;
                        toVisit.push({nr,nc});
                }
                
                
                }
            }
            
            min++;
        }

        return fresh==0 ? min : -1;
        
    }
};
