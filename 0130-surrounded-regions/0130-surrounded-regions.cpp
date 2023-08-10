class Solution {
public:
    
    void dfs(int i , int j , vector<vector<char>>& board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()){
            return;
        } 
        if(board[i][j] == 'O'){
            board[i][j] = '#';
            dfs(i+1,j,board);
            dfs(i,j+1,board);
            dfs(i-1,j,board);
            dfs(i,j-1,board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        //Do a DFS from the Border and then we will be able to Remove all those 'O' which we can't flip and then all the Remaing 'O''s can be those 'O' which we can flip. 
        
        //Will do a DFS from the First Row and First Column and the Last Row and the Last Column.
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0 ; i < m ; i++){
            if(board[0][i] == 'O') dfs(0,i,board);
        }
        for(int i = 0 ; i < n ; i++){
            if(board[i][0] == 'O') dfs(i,0,board);
        }
        for(int i = 0 ; i < m ; i++){
            if(board[n-1][i] == 'O') dfs(n-1,i,board);
        }
        for(int i = 0 ; i < n ; i++){
            if(board[i][m-1] == 'O') dfs(i,m-1,board); 
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};