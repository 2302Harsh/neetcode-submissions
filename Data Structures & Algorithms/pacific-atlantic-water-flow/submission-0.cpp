class Solution {

    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        queue<pair<int,int>> atlQueue, pacQueue;

        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols,false));

        for(int r=0; r<rows; ++r){
            pacQueue.push({r,0});
            atlQueue.push({r,cols-1});
        }

        for(int c=0; c<cols; ++c){
            pacQueue.push({0,c});
            atlQueue.push({rows-1,c});
        }

        bfs(pacQueue, pac, heights);
        bfs(atlQueue, atl, heights);

        vector<vector<int>> res;

        for(int r=0; r<rows; ++r){
            for(int c=0; c<cols; ++c){
                if(atl[r][c] && pac[r][c]) res.push_back({r,c});
            }
        }

        return res;
    }

private:
    void bfs(queue<pair<int,int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            ocean[row][col] = true;

            for(int i =0; i<4; i++){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];

                if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() && !ocean[nr][nc] && heights[row][col]<=heights[nr][nc]){
                    q.push({nr,nc});
                }
            }
        }
    }
};
