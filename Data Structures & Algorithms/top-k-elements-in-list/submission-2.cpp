class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> seen;

        for(int num : nums){
            seen[num]++;
        }

        priority_queue<pair<int,int>> pq;

        for( auto s : seen){
            pq.push({s.second, s.first});
        }

        vector<int> ans;

        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};
