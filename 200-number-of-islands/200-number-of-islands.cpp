class Solution {
public:
    
    void helper(int i , int j , int r, int c, vector<vector<char>> &grid){
        if(i < 0 || j < 0 || i>=r || j>=c){
            return;
        }
        else if(grid[i][j]!='1'){
            return;
        }
        else if(grid[i][j]=='1'){
            grid[i][j]='2';
        }
        helper(i+1,j,r,c,grid);
        helper(i,j+1,r,c,grid);
        helper(i-1,j,r,c,grid);
        helper(i,j-1,r,c,grid);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //from one point explore all the four directions of it
        int r = grid.size();
        int c = grid[0].size();
        int islands = 0;
        //DFS will be used here
        //First we have to find the starting point or any point of an island
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(grid[i][j]=='1'){
                    islands++;
                    helper(i,j,r,c,grid);//Now from here i will explore all the four sides of the island
                }
            }
        }
        return islands;
    }
};