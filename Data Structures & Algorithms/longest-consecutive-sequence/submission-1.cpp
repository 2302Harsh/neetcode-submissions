class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num : nums){
            seen.insert(num);
        }

        int ans =0;

        for(int num : nums){
            if(seen.find(num-1) == seen.end()){
                int n = num;
                int count = 0;
                while(seen.find(n) != seen.end()){
                    count++;
                    n++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};
