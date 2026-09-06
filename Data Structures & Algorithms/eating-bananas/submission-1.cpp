class Solution {
public:

    int calculateHours(vector<int>& arr, int speed){
            int totalHrs = 0;
            for(int i=0; i<arr.size(); i++){
                totalHrs += ceil((double)arr[i]/speed);
            }
            return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxPile = *max_element(piles.begin(),piles.end());
        int low = 1, high = maxPile;
        int ans = maxPile;

        while(low<=high){
            int mid = (low + high)/2;
            int totalHrs = calculateHours(piles,mid);

            if(totalHrs<=h){
                ans = mid;
                high = mid-1;
            }
            else{
                low =mid+1;
            }
        }
        return ans;
    }
};
