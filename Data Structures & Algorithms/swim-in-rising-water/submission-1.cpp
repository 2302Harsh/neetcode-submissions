class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        set<pair<int,int>> visit;

        vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

        minHeap.push({grid[0][0],0,0});
        visit.insert({0,0});

        int t =0;
        while(!minHeap.empty()){
            vector<int> node = minHeap.top();
            minHeap.pop();

            t = node[0];
            int r = node[1];
            int c = node[2];
            

            if(r == n-1 && c == n-1) return t;

            for(int i=0; i<4; i++ ){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];

                if(nr< 0 || nc<0 || nc == n || nr == n || visit.count({nr,nc})) continue;

                visit.insert({nr,nc});
                minHeap.push({max(t,grid[nr][nc]),nr,nc});
            }
        }

        return n*n;

    }
};
