class Solution {
public:
    /*
    int helper(int i, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        //Base Case
        if(i == 0){
            if(amount%coins[0]==0){
                return amount/coins[i];
            }
            else{
                return INT_MAX-1;
            }
        }
        int not_take = helper(i-1,coins,amount,dp);
        int take = INT_MAX;
        if(coins[i]<=amount){
            take = 1 + helper(i,coins,amount-coins[i],dp); 
        }
        dp[i][amount] = min(take,not_take);
        return dp[i][amount];
    }
    
    int coinChange(vector<int>& coins, int amount){
        //Memoization Solution
        //Now here two moving variables are the index and the target amount
        //"n" index means values range from 0 to n-1 
        //"target+1" means values from 0 to target as 0 can also be inclided as the target amount
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int a = helper(n-1,coins,amount,dp);
        if(a == INT_MAX || a == INT_MAX-1){ 
            //Now here INT_MAX-1 will come, when we are at the last index and the 
            //number of elements given to us is only 1, then this case will get executed.
            return -1;
        }
        return a;
        //TIme Complexity:- O(N*Target)
        //Space Complexity:- O(N*Target) + O(Target)[Auxillary Stack Space]
    }
    */
    int coinChange(vector<int>& arr, int T){
        //Dynamic Programming
        int n = arr.size();
       vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
    }
};