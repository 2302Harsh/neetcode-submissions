class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(),-1));
        return dfs(text1.size()-1, text2.size()-1, text1, text2, memo);
    }

    int dfs(int i, int j, string& text1, string& text2, vector<vector<int>>& memo){

        if(i<0 || j<0) return 0;

        if(memo[i][j] != -1) return memo[i][j];

        if(text1[i] == text2[j]) return memo[i][j] = 1+ dfs(i-1, j-1, text1, text2,memo);

        return memo[i][j] = max(dfs(i-1, j, text1, text2,memo), dfs(i, j-1, text1, text2,memo));
    }
};
