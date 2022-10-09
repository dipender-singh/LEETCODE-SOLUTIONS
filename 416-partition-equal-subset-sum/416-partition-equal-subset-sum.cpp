class Solution {
public:
    /*
    bool helper(int i, int sum , vector<int>& nums){
        //Now we just have to see that can we form the sum with the elemtns of the nums array or not.
        if(sum == 0){
            return true;
        }
        //A Base Case
        if(i == 0) return (sum == nums[0]);
        
        bool unpick = helper(i-1,sum,nums);
        bool pick = false;
        if(nums[i]<=sum){
            pick = helper(i-1,sum-nums[i],nums);
        }
        
        return pick || unpick;
    }
    
    
    bool canPartition(vector<int>& nums) {
        
/*
Now it simple if the sum of the numbers is odd then it is not possilbe to divide the sum into two equal parts, but when the sum is even it may or may not be possible.
*/
    /*
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            sum = sum + nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        return helper(n-1,sum/2,nums);
    }
*/
    
    bool helper(int i , int sum, vector<vector<int>> &dp, vector<int> &nums){
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(sum == 0){
            dp[i][sum] = 1;
            return true;
        }
        if(i == 0){
            return (sum == nums[0]);
        } 
        bool unpick = helper(i-1,sum,dp,nums);
        bool pick = false;
        if(nums[i]<=sum){
            pick = helper(i-1,sum-nums[i],dp,nums);
        }
        
        dp[i][sum] = pick || unpick;
        return dp[i][sum];
    }
    
    bool canPartition(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            sum = sum + nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return helper(n-1,sum/2,dp,nums);
    }
};
