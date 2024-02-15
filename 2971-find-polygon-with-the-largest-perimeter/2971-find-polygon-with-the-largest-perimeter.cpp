class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        //Brute Force
        sort(nums.begin(),nums.end());
        if(nums.size()<3){
            return -1;
        }
        if(nums.size() == 3){
            if(nums[0] + nums[1] <= nums[2]){
                return -1;
            }
        }
        long long int ans = -1;
        long long int sum = nums[0] + nums[1];
        int ind = 0;
        for(int i = 2; i < nums.size() ; i++){
            if(sum > nums[i]){
                ans = max(sum,ans);
                ind = i;
            }
            sum = sum + nums[i];
        }
        if(ans == -1){
            return -1;
        }
        return ans + nums[ind];
    }
};