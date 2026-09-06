class Solution {

    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        capture(board);

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(board[r][c] == 'O') board[r][c] = 'X';
                else if(board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }

private:
    void capture(vector<vector<char>>& board){

        queue<pair<int,int>> q;

        for(int r=0; r<board.size(); r++){
            for(int c=0; c<board[0].size(); c++){
                if(r == 0 || c ==0 || c == board[0].size()-1 || r == board.size()-1 && board[r][c] == 'O') q.push({r,c});
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(board[row][col] == 'O'){
                board[row][col] = 'T';
                for(int i=0; i<4; i++){
                    int nr = row + directions[i][0];
                    int nc = col + directions[i][1];
                    if(nc>=0 && nr>=0 && nc<board[0].size() && nr<board.size()){
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
};
