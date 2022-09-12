class Solution {
public:
    /*
    int helper(int i ,int j ,int m, int n, vector<vector<int>>& grid){
        if(i>=m || j>=n){
            return 101;
        }
        if(i==m-1 and j==n-1){
            return grid[i][j];
        }
        return grid[i][j] + min(helper(i+1,j,m,n,grid),helper(i,j+1,m,n,grid));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        //Recursion
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int m = grid.size();
        int n = grid[0].size();
        int ans = helper(0,0,m,n,grid);
        return ans;
    }
    */
    /*
    int helper(int i, int j, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(i>=m || j>=n){
            return -1;
        }
        if(i==m-1 and j==n-1){
            dp[i][j]=grid[i][j];
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right = helper(i,j+1,m,n,dp,grid);
        int down = helper(i+1,j,m,n,dp,grid);
        if(right == -1){
        dp[i][j] = grid[i][j] + down;     
        } 
        else if(down == -1){
            dp[i][j] = grid[i][j] + right;
        }
        else{
            dp[i][j] = grid[i][j] + min(right,down);
        }
        return dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid){
        //Memoization
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        int ans = helper(0,0,m,n,dp,grid);
        return ans;
        //Now the index i,j represents the minimum path sum from m,n to index i,j.
    }
    */
    //Dynamic Programming
    int minPathSum(vector<vector<int>>& grid){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        dp[0][0]=grid[0][0];
        for(int i = 1 ; i < n ; i++){
            dp[0][i] = grid[0][i] +dp[0][i-1];
        }
        for(int j = 1 ; j < m ; j++){
            dp[j][0] = grid[j][0] + dp[j-1][0];
        }
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
    
    
    
};