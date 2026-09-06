class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap <Integer,Integer> mp = new HashMap<>();

        for(int i=0; i<nums.length; i++){
            int remainder = target - nums[i];
            if(mp.containsKey(remainder)){
                return new int[]{
                    mp.get(remainder), i};
                
            }
            mp.put(nums[i],i);
        }

        return new int[] {};
    }
}
