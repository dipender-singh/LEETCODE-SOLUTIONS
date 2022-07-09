class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int ans = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]==target){
                ans = i;
            }
        }
        return ans;
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int ans = -1;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + ((high - low)/2);
            if(nums[mid]==target){
                return mid;
            }
            if(nums[low]<=nums[mid]){ // left part is sorted
                if(nums[low]<=target and nums[mid]>=target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]<=target and nums[high]>=target){
                    low=mid+1;
                }
                else{
                    high = mid-1;
                }
            }
    }
        return -1;
    }
};