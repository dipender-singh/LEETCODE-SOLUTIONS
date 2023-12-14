class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<int> row(n,0);
        vector<int> col(m,0);
        
        //We will find the Number of Ones and Zeroes in each Row and Column of the Grid. 
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                row[i] = row[i] + grid[i][j]; 
                col[j] = col[j] + grid[i][j]; 
            }
        }
        //Now what we have to do here. 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans[i][j] = 2*row[i] - grid.size() + 2*col[j] - grid[0].size(); 
            }
        }
        return ans;
    }
};