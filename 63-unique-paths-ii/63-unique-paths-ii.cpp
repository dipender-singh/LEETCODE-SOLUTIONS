class Solution {
public:
    /*
    int helper(int i, int j , int m , int n , vector<vector<int>>& obstacleGrid){
        if(i>=m || j>=n){
            return 0;
        }
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==m-1 and j==n-1){
            return 1;
        }
        return helper(i+1,j,m,n,obstacleGrid) + helper(i,j+1,m,n,obstacleGrid);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //Recursive Solution
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        int ans = helper(0,0,m,n,obstacleGrid);
        return ans;
    }
    */
    /*
    int helper(int i , int j , int m, int n , vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(i>=m || j>=n){
            return 0;
        }
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==m-1 and j==n-1){
            dp[i][j]=1;
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j] = helper(i+1,j,m,n,obstacleGrid,dp) + helper(i,j+1,m,n,obstacleGrid,dp);
        return dp[i][j];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //We will try using Memoization
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int ans = helper(0,0,m,n,obstacleGrid,dp);
        return ans;
        //Now here every index in dp[i][j] represents the number of unique ways from (i,j) to (m-1,n-1).
    }
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        //Dynamic Programming
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        dp[0][0] = 1;
        if(obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(i == 0 and j == 0){
                    dp[i][j]=1;
                    }
                else{
                    int right = 0;
                    int down = 0;
                    if(i>0 and obstacleGrid[i-1][j]!=1) right = dp[i-1][j];
                    if(j>0 and obstacleGrid[i][j-1]!=1) down = dp[i][j-1];
                    dp[i][j] = right+down;
                }
            }
        }
        return dp[m-1][n-1];
    }
};