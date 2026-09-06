class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0; row<9; row++){
            unordered_set<char> seen;
            for(int col=0; col<9; col++){
                if(board[row][col]=='.') continue;
                if(seen.find(board[row][col]) != seen.end()) return false;
                seen.insert(board[row][col]);
            }
        }

        for(int col=0; col<9; col++){
            unordered_set<char> seen;
            for(int row=0; row<9; row++){
                if(board[row][col] == '.') continue;
                if(seen.find(board[row][col]) != seen.end()) return false;
                seen.insert(board[row][col]);
            }
        }

        for(int row = 0; row<9; row+=3){
            for(int col=0; col<9; col+=3){
                unordered_set<char> seen;
                int sc = col;
                int ec = sc+2;
                int sr = row;
                int er = sr+2;

                for(int i=sr; i<=er; i++){
                    for(int j=sc; j<=ec; j++){
                        if(board[i][j]=='.') continue;
                        if(seen.find(board[i][j]) != seen.end()) return false;
                        seen.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};
