class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Brute Force
        int low = 0;
        int high = nums.size()-1;
        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low = mid + 1;
            }
            else if(nums[mid]>target){
                high = mid - 1;
            }
        }
       if(nums[low]!=target){
           return -1;
       } 
        return low;
    }
};