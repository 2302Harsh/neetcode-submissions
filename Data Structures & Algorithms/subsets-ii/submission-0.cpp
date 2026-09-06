class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>> res;

        for(int i=0; i< 1<<nums.size(); i++){
            vector<int> subset;

            for(int j=0; j<nums.size(); j++){
                if(i & 1<<j) subset.push_back(nums[j]);
            }

            sort(subset.begin(),subset.end());

            res.insert(subset);
        }

        vector<vector<int>> ans(res.begin(), res.end());

        return ans;

    }
};
