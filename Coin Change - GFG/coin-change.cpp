//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,0));
        
        //Initial Values
        for(int i = 0 ; i <= N ; i++){
            //i represents the Number of Items
            //When the sum is zero then there is only one way to not pick up any element
            dp[i][0] = 1;
        }
        for(int i = 0 ; i <= sum ; i++){
            //When the items are Zero then we can't form the Sum
            dp[0][i] = 0;
        }
        dp[0][0] = 0;
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <=sum ; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
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