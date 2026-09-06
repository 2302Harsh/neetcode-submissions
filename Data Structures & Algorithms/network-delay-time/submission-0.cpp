class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int,vector<pair<int,int>>> edges;

        for(const auto& time : times){
            edges[time[0]].emplace_back(time[1],time[2]);
        }

        priority_queue<pair<int,int>,vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0,k});

        set<int> visited;
        int t = 0;
        while(!minHeap.empty()){
            auto cur = minHeap.top();
            minHeap.pop();

            int weight = cur.first;
            int node = cur.second;

            if(visited.count(node)) continue;
            visited.insert(node);

            t = weight;

            for(const auto& edge : edges[node]){
                int node2 = edge.first, weight2 = edge.second;

                if(!visited.count(node2)) minHeap.push({weight + weight2, node2});
            }
        }

        return (visited.size() == n) ? t : -1;

    }
};
