class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> count;
        
        for(int i=0; i<nums.size(); i++){

            int num = nums[i];

            int reminder = target - nums[i];
            if( count.find(reminder) != count.end()){
                return {count[reminder],i};
            }
            count[num] = i;
        }
        return{};
    }
};
