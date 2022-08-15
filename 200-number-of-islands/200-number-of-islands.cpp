class Solution {
public:
    /*Using DFS
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
    // Time Complexity will be O(m*n)[this one is for the double for loop] + O(m*n)[this one is for traversing 
    // in the graph as we are visiting a 1 for only once in the graph and after visitng it we are marking it as 
    // 2 so that we after moving forward from 1 we can't again move backward to the 1 from where we can came 
    // forward so that's why we are marking the 1 which we have visited as 2 and so that's how our total TC for 
    // this will be O(m*n)] 
    */
    //Using BFS
    int dr[4] = {1 , 0 , -1 , 0}; //These numbers will be added to current index to reach 4 adjacent directions
    int dc[4] = {0 , 1 , 0 , -1}; //These numbers will be added to current index to reach 4 adjacent directions
    
    //Function to check that the adjacent directions of a partiuclar pair of indices are valid or not
    
    bool isvalid(int i, int j , int r, int c){
        if(i < 0 || j < 0 || i >= r || j >= c){
            return false;
        }
        return true;
    }
        
        
    int numIslands(vector<vector<char>>& grid){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //Now the implenentation of the BFS requires a queue
        int r = grid.size();
        int c = grid[0].size();
        int islands = 0;
        queue<pair<int,int>> q;
        for(int i = 0 ; i < r; i++){
            for(int j = 0 ; j < c ; j++){
                if(grid[i][j]=='1'){
                    islands++;
                    //Now BFS implementation will start
                    q.push({i,j});
                    while(q.size()!=0){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        //Now after reaching at a particular index so we have to explore it's 4 adjacent 
                        //directions, now before exploring all the 4 directions we first will do check that all
                        //these 4 directions are valid directios or not.
                        if(grid[x][y]=='1'){
                            grid[x][y]='2';
                         for(int i = 0 ; i < 4 ; i++){
                            if(isvalid(x+dr[i],y+dc[i],r,c)==true){
                                q.push({x+dr[i],y+dc[i]});
                            }
                        }   
                        }
                    }
                }
            }
        }
        return islands;
    }
    //Time Complexity:- O(m*n) and Space Complexity:- O(m*n)[for storing all cells in the queue] + O(4)
};