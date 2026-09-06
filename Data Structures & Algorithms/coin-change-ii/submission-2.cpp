class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>> memo(coins.size(), vector<int>(amount+1, -1));
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));

        for(int i = 0; i<=amount; i++){
            if(i%coins[0] == 0) dp[0][i] = 1;
            else dp[0][i]=0;
        }

        for(int i=1; i<coins.size();i++){
            for(int j=0; j<=amount; j++){
                int notTaken= dp[i-1][j];
                int taken = 0;
                if(coins[i]<=j) taken = dp[i][j-coins[i]];

                dp[i][j]= taken + notTaken;
            }
        }

        return dp[coins.size()-1][ amount];
    }

    int dfs(int i, int amount, vector<int>& coins, vector<vector<int>>& memo){

        if(i==0){
            if(amount%coins[0] == 0) return 1;
            else return 0;
        }

        if(memo[i][amount] != -1) return memo[i][amount];

        int notTaken = dfs(i-1, amount, coins, memo);
        int taken = 0;
        if(coins[i]<= amount) taken= dfs(i, amount-coins[i], coins, memo);

        return memo[i][amount] = notTaken+taken;
    }
};
