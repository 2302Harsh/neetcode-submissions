class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size()+1, vector<int>(text2.size()+1,0));

        for(int i=0; i<=text1.size(); i++){
            memo[i][0] = 0;
        }

        for(int j=0; j<=text2.size(); j++){
            memo[0][j] = 0;
        }

        for(int i=1; i<=text1.size(); i++){
            for(int j=1; j<=text2.size(); j++){
                if(text1[i-1] == text2[j-1]) memo[i][j] = 1+ memo[i-1][j-1];
                else memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
            }
        }

        return memo[text1.size()][text2.size()];
    }

    int dfs(int i, int j, string& text1, string& text2, vector<vector<int>>& memo){

        if(i<0 || j<0) return 0;

        if(memo[i][j] != -1) return memo[i][j];

        if(text1[i] == text2[j]) return memo[i][j] = 1+ dfs(i-1, j-1, text1, text2,memo);

        return memo[i][j] = max(dfs(i-1, j, text1, text2,memo), dfs(i, j-1, text1, text2,memo));
    }
};
