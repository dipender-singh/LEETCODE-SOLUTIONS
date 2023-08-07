class Solution {
public:
    
    void dfs(int i , int j , vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1'){
            return;
        }
        if(grid[i][j] == '1'){
            grid[i][j] = '2';
        }
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};