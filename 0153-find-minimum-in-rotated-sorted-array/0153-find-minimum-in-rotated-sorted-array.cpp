class Solution {
public:
    int findMin(vector<int>& nums) {
        /*Brute Force
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            ans = min(ans,nums[i]);
        }
        return ans;
        //Time Complexity: O(N)
        //Space Complexity: O(1)
        */
        //Better Approach: Will Use Binary Search
        //How we identified:
        //1. First observation was that we had a Sorted Array
        //2. And we have to find an element in kind of a Sorted Array
        //Rotation doesn't matter. 
        int n = nums.size();
        int low = 0;
        int high = n-1;
        //The case when the array is sorted, just compare the first and the last element.
        
        while(low < high){
            if(nums[low]<=nums[high]){
            return nums[low];
        }
            int mid = (low) + (high -low)/2;
            if(nums[mid] >= nums[low]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
    }
};