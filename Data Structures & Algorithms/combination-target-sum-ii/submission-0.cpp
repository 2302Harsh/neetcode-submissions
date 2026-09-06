class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, cur,0,0);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, vector<int> cur, int idx, int total){
        if(total == target){
            res.push_back(cur);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;

            if(total+candidates[i]>target) break;

            cur.push_back(candidates[i]);
            backtrack(candidates,target, cur, i+1,total+candidates[i]);
            cur.pop_back();
        }

        
    }

};
