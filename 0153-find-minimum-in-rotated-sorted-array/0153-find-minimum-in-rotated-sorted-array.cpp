class Solution {
public:
    int findMin(vector<int>& nums) {
        //Brute Force
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            ans = min(ans,nums[i]);
        }
        return ans;
    }
};