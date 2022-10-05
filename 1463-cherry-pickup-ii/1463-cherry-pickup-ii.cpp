class Solution {
public:
    /*
    int helper(int i, int j, int y ,int m, int n, vector<vector<int>>& grid){
        //Steps needed for the Recursion:-
        //1.) Base Case:- basically there will be two base cases one will be the base case when we will reach 
                        //the last row and the other will be the base case when we will go out of bound.
        //2.) Small Calculation 
        //3.) Recursive call 
        
        //This is the case when we go out of the boundries of the Matrix
        if(j < 0 || j >= n || y < 0 || y >= n){
            return -1;
        }
        
        if(i == m-1){ //If Alice have reached the last row then it is for sure that Bob would also have 
                      //reached the last row. So, now upon reaching the last row we just have to take care of 
                      //the column's in which Alice and Bob are.
            
            if(j == y){ //If both Alice and Bob are in the same column then we will consider only one
                return grid[i][j];
            }
            if(j != y){ //Now if Alice and Bob are not in the same row then we will return the sum of them
                return grid[i][j] + grid[i][y];
            }
        }
        
        //Now when Alice is moving then Bob is gonna move with it, now for every movement of Alice, Bob is 
        //having the option to move in any of the three directions.
        int maxi = INT_MIN;
        for(int d1 = -1 ; d1 < 2 ; d1++){
            for(int d2 = -1 ; d2 < 2 ; d2++){
               if(j != y) maxi = max(maxi,grid[i][j] + grid[i][y] + helper(i+1, j+d1, y+d2, m,n,grid));
                else maxi = max(maxi,grid[i][j] + helper(i+1,j+d1,y+d2,m,n,grid));
            }
        }
        
        return maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        //Recursive Solution
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        ans = helper(0,0,n-1,m,n,grid);
        //We will need to move Alice and Bob.
        return ans;
        //Now here each point represents the maximum cherries collected by both Alice and Bob from last row 
        //to that specific cell.
    }
    */
    
   int maxChocoUtil(int i, int j1, int j2, int n, int m, vector < vector < int >> 
& grid, vector < vector < vector < int >>> & dp) {
  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    return -1e9;

  if (i == n - 1) {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }

  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = INT_MIN;
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      int ans;
      if (j1 == j2)
        ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
      else
        ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n,
        m, grid, dp);
      maxi = max(maxi, ans);
    }
  }
  return dp[i][j1][j2] = maxi;
}

int cherryPickup(vector<vector<int>>& grid){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n = grid.size();
    int m = grid[0].size();

  vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector < int
  > (m, -1)));

  return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}
};