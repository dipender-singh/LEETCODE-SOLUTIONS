class Solution {
public:
    /*Recursive Solution
    int climbStairs(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //If there is 0 or 1 stair then there is only one way of going to that Stair Case
        if(n==0 || n==1){
            return 1;
        }
        return climbStairs(n-1)+climbStairs(n-2);
    }
    */
    
    /*Memoization Solution
    int helper(int n, vector<int> &dp){
        if(n==0 || n==1){
            dp[n]=1;
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = helper(n-1,dp)+helper(n-2,dp);
        return dp[n];
    }
    
    int climbStairs(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<int> dp(n+1,-1); //Here index 'i' represent the remaining number of StairCase's
        dp[0]=1;
        dp[1]=1;
        int a = helper(n,dp);
        return dp[n];
    }
    */
    //Dynamic Programming Solution
    int climbStairs(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};