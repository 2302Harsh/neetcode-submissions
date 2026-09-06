class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,int>> pairT;

        for(int i=0; i<speed.size(); i++){
            pairT.push_back({position[i],speed[i]});
        }

        sort(pairT.rbegin(),pairT.rend());

        int fleet = 1;
        double prevTime = (double)(target-pairT[0].first)/ pairT[0].second;

        for(int i=1; i<speed.size(); i++){
            double currTime = (double)(target-pairT[i].first)/ pairT[i].second;
            if(currTime>prevTime){
                fleet++;
                prevTime = currTime;
            }
        }
        return fleet;
    }
};
