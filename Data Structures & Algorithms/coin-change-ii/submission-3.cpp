class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>> memo(coins.size(), vector<int>(amount+1, -1));
        // vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        vector<int> row(amount+1, 0);

        for(int i = 0; i<=amount; i++){
            if(i%coins[0] == 0) row[i] = 1;
            else row[i]=0;
        }

        for(int i=1; i<coins.size();i++){
            vector<int> newRow(amount+1, 0);
            for(int j=0; j<=amount; j++){
                int notTaken= row[j];
                int taken = 0;
                if(coins[i]<=j) taken = newRow[j-coins[i]];

                newRow[j]= taken + notTaken;
            }

            row = newRow;
        }

        return row[ amount];
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
