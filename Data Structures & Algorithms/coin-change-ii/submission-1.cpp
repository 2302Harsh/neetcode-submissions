class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount+1, -1));
        return dfs(coins.size()-1, amount, coins, memo);
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
