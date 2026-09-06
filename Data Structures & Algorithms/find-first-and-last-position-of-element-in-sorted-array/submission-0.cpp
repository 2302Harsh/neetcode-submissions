class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binary_search(nums, target, true);
        int right = binary_search(nums, target, false);

        return {left, right};
        
    }

    int binary_search(vector<int> nums, int target, bool left_bais){
        int l =0;
        int r = nums.size()-1;
        int i=-1;
        

        while(l<=r){
            int mid = (l + r)/2;
            if(nums[mid]<target){
                l = mid+1;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
            else{
                i = mid;
                if(left_bais) r = mid-1;
                else l = mid +1;
            }
        }

        return i;
    
    }
};