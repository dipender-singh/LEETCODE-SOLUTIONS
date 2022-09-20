// Was asked in Online Round of Dream-11
class Solution {
public:
    /*
    int helper(int i, int j, int m, int n, vector<vector<int>>& matrix){
       if( j < 0 || j >= n){
            return INT_MAX;
        }
        if( i == m-1 ){
            return matrix[i][j];
        }
        int same = helper(i+1,j,m,n,matrix);
        int left = helper(i+1,j-1,m,n,matrix);
        int right = helper(i+1,j+1,m,n,matrix);
        return matrix[i][j] + min(left,min(same,right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //Recursive Solution
        int ans = INT_MAX;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int x = 0 ; x < n ; x++){
        ans = min(ans,helper(0,x,m,n,matrix));   
        }
        return ans;
    }
    */
    
    int helper(int i, int j, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if( j < 0 || j >= n){
            return INT_MAX;
        }
        if( i == m-1 ){
            dp[i][j] = matrix[i][j];
            return matrix[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int same = helper(i+1,j,m,n,matrix,dp);
        int left = helper(i+1,j-1,m,n,matrix,dp);
        int right = helper(i+1,j+1,m,n,matrix,dp);
        dp[i][j] = matrix[i][j] + min(left,min(same,right));
        return dp[i][j];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix){
        //Memoization Solution
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int ans = INT_MAX;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        for(int x = 0 ; x < n ; x++){
        ans = min(ans,helper(0,x,m,n,matrix,dp));   
        }
        return ans;
    }
};