class Solution {
public:
    /*
    int helper(int i , int j, int m, int n){
        if(i>=m || j>=n){
            return 0;
        }
        if(i == m-1 || j == n-1){ 
            //This means that when we are in the last row or in the last column then we have only one path to 
            //reach the last cell and that is through that particular last row or last column. 
            return 1;
        }
        int right = helper(i,j+1,m,n);
        int down = helper(i+1,j,m,n);
        //Then after calculating the ways through a particular cell by taking one step right and one step 
        //down. We will return the total number of paths and that will be equal to the sum of number of paths 
        //we get by taking one step right and one step down.  
        return right+down;
    }
    
    int uniquePaths(int m, int n) {
      //Revisiting in Striver's DP Series
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //Using Recursion
        int ans = 0;
        ans = helper(0,0,m,n);
        return ans;
    }
    */
    /*
    int helper(int i, int j, int m , int n, vector<vector<int>> &dp){
        if(i>=m || j >=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==m-1 || j == n-1){
            dp[i][j]=1;
            return 1;
        }
        int right = helper(i,j+1,m,n,dp);
        int down = helper(i+1,j,m,n,dp);
        dp[i][j] = right + down;
        return right+down;
    }
    
    int uniquePaths(int m, int n){
        //Now using Memoization
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //A vector having m elements and each element is a vector of size 'n'.
        vector<vector<int>> dp( m , vector<int> (n, -1)); 
        //Now we know that when we are in the last row or last column then to reach the destination there 
        //will only be a single path.
        
        int ans = helper(0,0,m,n,dp);
        return ans;
    }
    */
    int uniquePaths(int m, int n){
        //Now using Dynamic Programming
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //A vector having m elements and each element is a vector of size 'n'.
        vector<vector<int>> dp( m , vector<int> (n, 0)); 
        for(int i = 0 ; i < n ; i++){
            dp[0][i] = 1; //Because when we are in the first row and we are moving in the first row then we 
                          //are moving on the same path so the number of unique paths in the first row will 
                          //be '1'.
        }
        for(int i = 0 ; i < m ; i++){
            dp[i][0] = 1; //Because when we are in the first column and we are moving in the first column
                          //then we are moving on the same path so the number of unique paths in the first 
                          //column will be '1'.
        }
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};