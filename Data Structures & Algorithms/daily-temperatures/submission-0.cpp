class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int,int>> prev;

        for(int i=0; i<temperatures.size(); i++){
            while(!prev.empty() && temperatures[i]>prev.top().first){
                res[prev.top().second] = i - prev.top().second;
                prev.pop();
            }
            prev.push({temperatures[i],i});
        }
        return res;
    }
};
