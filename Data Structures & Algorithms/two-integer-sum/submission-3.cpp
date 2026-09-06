class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> seen;
        vector<int> ans;

        for(int i =0; i< nums.size(); i++){
            int remainder = target - nums[i];
            if(seen.find(remainder) != seen.end()){
                ans.push_back(seen[remainder]);
                ans.push_back(i);
            }
            seen[nums[i]] = i;
        }

        return ans;

    }
};
