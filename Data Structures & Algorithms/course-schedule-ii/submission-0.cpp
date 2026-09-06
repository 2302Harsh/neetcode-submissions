class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        vector<vector<int>> adj(numCourses);

        for(auto& pre : prerequisites){
            inDegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int nei: adj[node]){
                inDegree[nei]--;
                if(inDegree[nei] == 0) q.push(nei);
            }
        }

        reverse(ans.begin(),ans.end());

        return (ans.size()==numCourses) ? ans : vector<int> ();
    }
};
