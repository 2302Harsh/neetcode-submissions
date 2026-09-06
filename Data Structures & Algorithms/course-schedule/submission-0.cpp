class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(int i=0; i<prerequisites.size(); i++){
            inDegree[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0) q.push(i);
        }

        int finish =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            finish++;
            for(int nei : adj[node]){
                inDegree[nei]--;
                if(inDegree[nei]==0) q.push(nei);
            }
        }

        return finish == numCourses;
    }
};
