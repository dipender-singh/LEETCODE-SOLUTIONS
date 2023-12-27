//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int helper(int i , int N , int W , int val[] , int wt[],vector<vector<int>>& dp){
        if(i >= N){
            return 0;
        }
        if(W == 0){
            dp[i][W] = 0;
            return 0;
        }
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        int take = 0;
        int nottake = 0;
        if(wt[i] <= W){
            take = val[i] + helper(i,N,W-wt[i],val,wt,dp);
        }
        nottake = helper(i+1,N,W,val,wt,dp);
        dp[i][W] = max(take,nottake);
        return max(take,nottake);
    }


    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return helper(0,N,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends