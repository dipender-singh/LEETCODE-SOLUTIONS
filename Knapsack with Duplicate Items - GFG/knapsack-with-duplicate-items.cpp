//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        //Dynamic Programming
        vector<vector<int>> dp(N+1, vector<int>(W+1,0));
        //When the Number of Elements are Zero then Max Profit will also be Zero.
        //When the Weight of the KnapSack is Zero, then the Profit will also be ultimatley Zero. 
        
        for(int i = 0 ; i <= W ; i++){
            dp[0][i] = 0;
        }
        for(int i = 0 ; i <= N ; i++){
            dp[i][0] = 0;
        }
        
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= W ; j++){
                //Here also we will have to stimulate the Process of Pick and Not Pick. 
                if(wt[i-1] <= j){
                    //If the Weight of the Current Element is less than the Current Weight of the KnapSack
                    dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i][j-wt[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][W];
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