class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // better
    
        // unordered_map<int,int> mp;
        // for(int n : nums){
        //     mp[n]++;
        // }

        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // for(auto& m : mp){
        //     pq.push({m.second, m.first});
        //     if(pq.size()>k){
        //         pq.pop();
        //     }
        // }

        // vector<int> res;
        // for(int i=0; i<k; i++){
        //     res.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return res;

        // optimal 

        unordered_map<int,int> mp;
        for(int n: nums){
            mp[n]++;
        }

        vector<vector<int>> freq(nums.size()+1);
        for(auto& m:mp){
            freq[m.second].push_back(m.first);
        }

        vector<int> res;
        for(int i=freq.size()-1; i>0; i--){
            for(int n: freq[i]){
                res.push_back(n);
                if(res.size() == k) return res;
            }
        }

        return res;
    }
};
