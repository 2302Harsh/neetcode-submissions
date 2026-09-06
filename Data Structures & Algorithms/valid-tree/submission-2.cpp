class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n-1) return false;
        if(n==1) return true;

        vector<int> degree(n,0);
        vector<vector<int>> adj(n);

        for(auto& edge : edges){
            degree[edge[1]]++;
            degree[edge[0]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(degree[i]==1) q.push(i);
        }

        // vector<int> topo;
        int count = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            // topo.push_back(node);
            count++;

            for(int nei : adj[node]){
                degree[nei]--;
                if(degree[nei] == 1) q.push(nei);
            }
        }

        return count == n;
    }
};
