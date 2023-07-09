class Solution {
public:
    
    int checkforzero(vector<vector<int>>& board, int i, int j){
        int n = board.size();
        int m = board[0].size();
       if(i < 0 || j < 0 || i>=n || j >= m){
           return 0;
       }
       if(board[i][j] == 1){
           return 1;
       }
       return 0; 
    }
    int checkforone(vector<vector<int>>& board, int i, int j){
        int n = board.size();
        int m = board[0].size();
       if(i < 0 || j < 0 || i>=n || j >= m){
           return 0;
       }
       if(board[i][j] == 1){
           return 1;
       }
       return 0;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        //Brute Force
        //Similar to the Set Matrix Zeroes. 
        //We can use a Space of O(n*m)
        int n = board.size();
        int m = board[0].size();
        
        //Live Cell -> 1
        //Dead Cell -> 0
        
        /*
        Any cell with Value 1 with fewer than "two" neighbors cells with value 1 becomes 0 as if caused by under-population.
        Any cell with Value 1 having two or three neighbors with Value 1 lives on to the next generation.
        Any cell with Value 1 with more than three neighbors with Value 1 becomes 0, as if by over-population.
        Any cell with Value 0 with exactly three neighbors with Value 1 becomes a cell with value 1, as if by reproduction.
        */
        vector<vector<int>> ans(n, vector<int> (m,-1));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans[i][j] = board[i][j];
            }
        }
         for(int i = 0 ; i < n ; i++){
         for(int j= 0 ; j < m ; j++){
            if(board[i][j] == 0){
                    int countforzero = 
                     checkforzero(board,i,j+1) +
                     checkforzero(board,i+1,j) + 
                     checkforzero(board,i-1,j) + 
                     checkforzero(board,i,j-1) + 
                     checkforzero(board,i-1,j-1) + 
                     checkforzero(board,i+1,j+1) + 
                     checkforzero(board,i-1,j+1) + 
                     checkforzero(board,i+1,j-1);
                    if(countforzero == 3){
                        ans[i][j] = 1;
                    }
                }
                else if(board[i][j] == 1){
                    int countforone =
                    checkforone(board,i,j+1) + 
                    checkforone(board,i+1,j) + 
                    checkforone(board,i-1,j) + 
                    checkforone(board,i,j-1) + 
                    checkforone(board,i-1,j-1) + 
                    checkforone(board,i+1,j+1) + 
                    checkforone(board,i-1,j+1) + 
                    checkforone(board,i+1,j-1);
                    if(countforone == 2 || countforone == 3){
                        ans[i][j] = 1;
                    }
                    else{
                        ans[i][j] = 0;
            }
        }
    }
}
    ///Now we have to copy the ans array to the Board array
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            board[i][j] = ans[i][j];
        }
    }
    }
};