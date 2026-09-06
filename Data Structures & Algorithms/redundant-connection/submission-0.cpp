class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> indegree (edges.size()+1,0);
        vector<vector<int>> adj(edges.size()+1);

        for(auto& edge : edges){
            indegree[edge[1]]++;
            indegree[edge[0]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;

        for(int i=1; i<=edges.size(); i++){
            if(indegree[i] == 1) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei] == 1) q.push(nei);
            }
        }

        for(int i = edges.size()-1; i>=0; i--){
            if(indegree[edges[i][0]] == 2 && indegree[edges[i][1]]==2) return {edges[i][0], edges[i][1]};
        }

        return {};
    }
};
