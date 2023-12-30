//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  long long int helper(int i, int coins[], int N, int sum, vector<vector<long long int>>& dp){
      if(i >= N || sum < 0){
          return 0;
      }
      if(dp[i][sum]!=-1){
          return dp[i][sum];
      }
      if(sum == 0){
          dp[i][sum] = 1;
          return 1;
      }
      long long int take = 0;
      long long int nottake = 0;
      if(coins[i]<=sum){
          take = helper(i,coins,N,sum-coins[i],dp);
      }
      nottake = helper(i+1,coins,N,sum,dp);
      dp[i][sum] = take+nottake;
      return take+nottake;
  }
  
    long long int count(int coins[], int N, int sum) {
        //We have to find the Number of Ways we get the Sum equal to the Target Sum, so for this 
        //we will have to explore different Combinations of Coins.
        
        //And Exploration of different Combinations leads to Recursion.
        
        //Given an infinite supply of each type of coin. 
        //And you can use any coin as many times as you want, relates to Unbounded Knapsack 
        vector<vector<long long int>> dp(N,vector<long long int>(sum+1,-1));
        return helper(0,coins,N,sum,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends