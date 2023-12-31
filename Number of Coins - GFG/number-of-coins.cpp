//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	long long int helper(int i, vector<int> &coins, int n, int sum, vector<vector<long long int>>& dp){
	    //Base Case
	    if(sum == 0){
	        dp[i][sum] = 0;
	        return 0;
	    }
	    if(i >= n){
	        return INT_MAX;
	    }
	    if(dp[i][sum] != -1){
	        return dp[i][sum];
	    }
	    long long int take = INT_MAX;
	    long long int nottake = INT_MAX;
	    if(coins[i] <= sum){
	        take = 1 + helper(i,coins,n,sum-coins[i],dp);
	    }
	   nottake = helper(i+1,coins,n,sum,dp);
	   dp[i][sum] = min(take,nottake);
	   return min(take,nottake);
	}
	
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<long long int>> dp(M,vector<long long int>(V+1,-1));
	    int ans = (int)helper(0,coins,M,V,dp);
	    if(ans == INT_MAX){
	        return -1;
	    }
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends