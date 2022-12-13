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
    //Now here index (i,j) represents the minimum path sum to reach the last row form the index (i,j).
    //Time Complexity:- Will be exploring 3 paths from each cell and there are 'n' rows in total, so we can
    //say that TC will be 3^n.
    */
    /*
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
        //Now here what does a particular pair of index (i,j) will represent ??
        //Here a particular index i,j will represent the minimum falling path sum from any cell of last row 
        //to a specific choosen cell with indices suppose (x,y) in a different row.
        
        //If we say in easy words, if we are at an index of (x,y) then that index (x,y) in the dp matrix will 
        //store the minimum sum of falling path of moving from last row (column chossen will be having the  
        //smallest value because of the given conditions, and also can be any column) to that partiuclar  
        //index pair of (x,y).
        
        //Time Complexity:- O(m*n)
        //Space Complexity:- O(m*n)
    }
    */
    /*
    int minFallingPathSum(vector<vector<int>>& matrix){
        //Dynamic Programming or Tabulation or Bottom Up means that we will use the base case to calculate 
        //the final results so meaning that we will move from top toward the  last row of the given matrix.
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        //Now here also we will move from bottom towards up
        for(int i = 0 ; i < n ; i++){
            dp[0][i] = matrix[0][i];
        }
        
        for(int i = 1 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int l = 1e9;
                int r = 1e9;
                int u = dp[i-1][j];
               if(j-1 >= 0) l = dp[i-1][j-1]; //Just have to take care of this edge case and that's it
               if(j+1 <= n-1) r = dp[i-1][j+1]; //Just have to take care of this edge case and that's it
                
                dp[i][j] = min(u,min(l,r)) + matrix[i][j];
            }
        }
        //Now all the values to reach to the last row from different columns in te first row will be stored 
        //in the last row. So we will just have to select the minimum possible value in the last row.
        int ans = dp[m-1][0];
        for(int i = 0 ; i < n ; i++){
            ans = min(ans,dp[m-1][i]);
        }
        return ans;
    }
    */
    int minFallingPathSum(vector<vector<int>>& matrix){
        //Space Optimization
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> pre(n,0);
        for(int i = 0 ; i < n ; i++){
            pre[i] = matrix[0][i];
        }
        
        for(int i = 1 ; i < m ; i++){
            vector<int> curr(n,0);
            for(int j = 0 ; j < n ; j++){
                int l = 1e9;
                int r = 1e9;
                int u = pre[j];
                if( j-1 >= 0) l = pre[j-1];
                if( j+1 <= n-1) r = pre[j+1];
                
                curr[j] = min(u,min(l,r)) + matrix[i][j];
            }
            pre=curr;
        }
        int ans = pre[0];
        for(int i = 0 ; i < n ; i++){
            ans = min(ans,pre[i]);
        }
        return ans;
    }
};