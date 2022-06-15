class Solution {
public:
    // BRUTE FORCE USING RECURSION
   /* TC:- O(2^(N+M))
    int calculate(int i , int j, int r , int c){
        if( i >= r || j >= c ){ // we have crossed the specified boundaries
            return 0;
        }
        if(i==r-1 || c==j-1){ // we have reached the final destination 
            return 1;
        }
        int ans1=0,ans2=0;
         ans1 = calculate(i+1,j,r,c); //TC: O(2^N)
         ans2 = calculate(i,j+1,r,c); //TC: O(2^M)
         return ans1+ans2;
    }
    
    int uniquePaths(int m, int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int ans=0;
        ans = calculate(0,0,m,n);
        return ans;
    }
    */
    /*MEMOIZATION:- SAVING THE VALUES IN A MATRIX
    int memoization(vector<vector<int>> &ans , int i , int j , int m, int n){ 
        if(ans[i][j]!=0){
            return ans[i][j];
        }
        if(i==m-1 || j == n-1){
            return 1;
        }
        int ans1=0;
        int ans2=0;
        ans1 = memoization(ans,i+1,j,m,n);
        ans2 = memoization(ans,i,j+1,m,n);
        ans[i][j]=ans1+ans2;
        return ans[i][j];
    }
    
    int uniquePaths(int m, int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);  
        vector<vector<int>> ans(m, vector<int> (n,0));
        int a = memoization(ans,0,0,m,n);
        // last se chal ke mere answer pehle index a gya wohi maine return kara diya
        // iska matlab mein 2d matrix mein sabse niche se travel karke sabse upar aaya
        // in this approach my index (i,j) represents the number of unique paths from (i,j) to
        // (m-1,n-1)
        return a;
        }
        TC: O(M*N) BECAUSE WE ARE CALCULATING AND STORING THE VALUES IN 2D MATRIX WE ARE DOING 
          RECURSIVE CALLS BUT WE ARE CHECKING IF A VALUE IS ALREADY THERE FOR THE SPECIFIC VALUES OR 
          NOT AND THAT VALUE WE ARE LOOKING IN THE 2D MATRIX ITSELF SO IT IS LIKE WE ARE MOVING IN A 
          2D MATRIX ITSELF
        SC: O(M*N) BECAUSE WE ARE CALCULATING AND STORING THE VALUES IN 2D MATRIX
        */
    /*DP APPROACH : ab mai upar se chalte hue niche jaunga or mera answer obviously array ke sabse
                 // last index pe stored hoga
    // now at (i,j) there will be the number of unique paths one can take to reach (i,j) from (0,0)
    int uniquePaths(int m, int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<vector<int>> dp(m,vector<int>(n,1)); //this will make a 2d vector of m*n with all 0
        dp[0][0]=1;
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
   /* TC: O(M*N) BECAUSE WE ARE CALCULATING AND STORING THE VALUES IN 2D MATRIX WE ARE DOING 
          RECURSIVE CALLS BUT WE ARE CHECKING IF A VALUE IS ALREADY THERE FOR THE SPECIFIC VALUES OR 
          NOT AND THAT VALUE WE ARE LOOKING IN THE 2D MATRIX ITSELF SO IT IS LIKE WE ARE MOVING IN A 
          2D MATRIX ITSELF
        SC: O(M*N) BECAUSE WE ARE CALCULATING AND STORING THE VALUES IN 2D MATRIX
     */
    int uniquePaths(int m, int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<int> dp(n,1);
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                dp[j] = dp[j]+dp[j-1];
            }
        }
        return dp[n-1];
    }
};