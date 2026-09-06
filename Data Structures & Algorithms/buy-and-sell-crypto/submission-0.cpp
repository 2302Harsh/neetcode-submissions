class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX;
        int maxP = 0;

        for(int i=0; i<prices.size(); i++){
            minP = min(minP,prices[i]);
            if(prices[i]>minP){
                int profit = prices[i]-minP;
                maxP = max(maxP,profit);
            }
        }

        return maxP;
    }
};
