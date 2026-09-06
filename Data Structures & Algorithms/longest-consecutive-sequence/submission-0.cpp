class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int longest =0;
        int lastSmaller = INT_MIN;
        int curr = 0;

        for(int i=0; i<nums.size(); i++){
            if (lastSmaller == nums[i]-1){
                curr++;
                lastSmaller=nums[i];
            }
           

            else if(nums[i] != lastSmaller) {
                curr=1;
                lastSmaller=nums[i];
            }

            longest = max(longest,curr);
        }
        return longest;
    }
};
