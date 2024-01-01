//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(vector<int> &coins, int n, int sum) 
	{ 
	    //Your code goes here
	    //Dynamic Programming
	    vector<vector<long long int>> dp(n+1,vector<long long int>(sum+1,0));
	    
	    for(int i = 0 ; i <= n ; i++){
	        dp[i][0] = 0;
	    }
	    for(int i = 0 ; i <= sum ; i++){
	        dp[0][i] = INT_MAX;
	    }
	    for(int i = 1 ; i <= sum ; i++){
	        if(i%coins[0] == 0){
	            dp[1][i] = i/coins[0];
	        }
	        else{
	            dp[1][i] = INT_MAX;
	        }
	    }
	    //Try to think via making the DP Matrix to think waht we can fill in the DP[i][j]. 
	    for(int i = 1 ; i <= n ; i++){
	        for(int j = 1 ; j <= sum ; j++){
	            if(coins[i-1] <= j){
	                dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    int ans = (int)dp[n][sum];
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