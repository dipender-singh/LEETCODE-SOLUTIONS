//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       //Dynamic Programming
       vector<vector<int>> dp(n+1, vector<int> (W+1,0));
       //Now we have to think of initial values
       
       dp[0][0] = 0;
      //Now when the weight of the bag is zero then whatever be the element we will not be able to store it
      for(int i = 0 ; i <= n ; i++){
          dp[i][0] = 0;
      }
      for(int i = 0 ; i <= W ; i++){
          dp[0][i] = 0; 
      } 
       
       //Now we will move onto the further soultion
       for(int i = 1 ; i <= n ; i++){
           for(int j = 1 ; j <= W ; j++){
               if(wt[i-1]<=j){
                   dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j]);
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends