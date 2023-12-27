//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  int helper(int i, int price[], int n, int len, vector<vector<int>>& dp){
      if(i >= n || len < 0){
          return 0;
      }
      if(len == 0){
          dp[i][len] = 0;
          return 0;
      }
      if(dp[i][len]!=-1){
          return dp[i][len];
      }
      int take = 0;
      int nottake = 0;
      
      //If i decide to cut the Rod from the Index i.
      //Now when can we make the cut. 
      if((i+1) <= len){
      take = price[i] + helper(i,price,n,len-(i+1),dp);
      }
      //If i decide to not cut the rod from the Index i.
      nottake = helper(i+1,price,n,len,dp);
      dp[i][len] = max(take,nottake);
      return max(take,nottake);
      
  }
  
    int cutRod(int price[], int n) {
        //code here
        //Maximize the Profit by Cutting up the Rod and selling the Pieces. 
        //And i also figured out why this belongs to Unbounded Knapsack.
        //And the fact that this question was asked in google this is kinda on the easy side. 
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(0,price,n,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends