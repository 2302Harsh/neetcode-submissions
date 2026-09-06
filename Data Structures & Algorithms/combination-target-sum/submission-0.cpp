class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        backtrack(nums, target,cur,0);
        return res;
    }

    void backtrack(vector<int>& nums, int target, vector<int>& cur, int index){
        if(target == 0){
            res.push_back(cur);
            return;
        }

        if(target<0 || index>=nums.size()) return;

        cur.push_back(nums[index]);
        backtrack(nums, target-nums[index],cur, index);
        cur.pop_back();
        backtrack(nums,target, cur, index+1);
    }
};
