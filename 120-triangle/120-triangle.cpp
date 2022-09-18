class Solution {
public:
    /*
    int helper(int i, int j, int m, int n, vector<vector<int>>& triangle){
        if(i == m-1){
            return triangle[i][j];
        }
        int same = helper(i+1,j,m,n,triangle);
        int diagonal = helper(i+1,j+1,m,n,triangle);
        return triangle[i][j] + min(same,diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        //Recursion
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int m = triangle.size();
        int n = triangle[m-1].size();
        int ans = 0;
        ans = helper(0,0,m,n,triangle);
        return ans;
    }
    */
    /*
    int helper(int i , int j , int m, int n , vector<vector<int>>& triangle , vector<vector<int>>& dp){
        if(i == m-1){
            dp[i][j] = triangle[i][j];
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int same = helper(i+1,j,m,n,triangle,dp);
        int diagonal = helper(i+1,j+1,m,n,triangle,dp);
        dp[i][j] = triangle[i][j] + min(same,diagonal);
        return dp[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& triangle){
        //Memoization
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int m = triangle.size();         //Number of Rows
        int n = triangle[m-1].size();    //Number of Columns
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int ans = helper(0,0,m,n,triangle,dp);
        return ans;
    }
    */
    /*
    int minimumTotal(vector<vector<int>>& triangle){
        //Dynamic Programming
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        
        //Now here in this question for the DP part we will move from bottom towards top
        for(int i = 0 ; i < n ; i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i = m-2 ; i >= 0 ; i--){
            for(int j = 0 ; j < triangle[i].size() ; j++){
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j]; 
            }
        }
        return dp[0][0];
    }
    */
    int minimumTotal(vector<vector<int>>& triangle){
        //Space Optimization
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int m = triangle.size();
        int n = triangle[m-1].size();
        //Now i'm only concerned with current values and previous values
        vector<int> pre(n,0);
        for(int i = 0 ; i < n ; i++){
            pre[i] = triangle[m-1][i];
        }
        for(int i = m-2 ; i >= 0 ; i--){
            vector<int> curr(n,0);
            for(int j = 0 ; j < triangle[i].size() ; j++){
                curr[j] = min(pre[j],pre[j+1]) + triangle[i][j];
            }
            swap(curr,pre);
        }
        return pre[0];
    }
};