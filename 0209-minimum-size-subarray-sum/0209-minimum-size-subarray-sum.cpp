class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //Basic Approach is this that we will keep on adding the numbers to the Sum and moving the J pointer, now when we get the sum greator than or Equal to the target we will keep on removing the elements which are pointed by the Ith pointer and will keep on finding the size of the window and will keep on increasing the Ith Pointer. 
        int n = nums.size();
        int i = 0 , j = 0 , sum = 0, size = INT_MAX;
        while(j<n){
            sum = sum + nums[j];
            while(sum >= target){
                sum = sum - nums[i];
                size = min(size, j-i+1);
                i++;
            }
            j++;
        }
        if(size!=INT_MAX){
            return size;
        }
        return 0;
    }
};