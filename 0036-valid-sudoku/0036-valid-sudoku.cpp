class Solution {
public:
        bool validBox(vector<vector <char>> &board){
            map<char, int> mp;
             for (int x = 0; x < 9; x = x + 3){
                for (int y = 0; y < 9; y = y + 3){
                    for (int i = x; i < x + 3; i++){
                        for (int j = y; j < y + 3; j++){
                            mp[board[i][j]]++;
                            if ((mp[board[i][j]] > 1 and board[i][j]!=46)){ //Here i am only checking that there is not any 
                                                                            //Duplicate number in a 3*3 Grid. 
                                return false;
                            }
                        }
                    }
                    mp.clear();
                }
            }
            return true;
        }

        bool validRow(vector<vector <char>> &board){
            vector<int> row(10,0);
            for(int i = 0 ; i < 9 ; i++){
                for(int  j = 0 ; j < 9 ; j++){
                    if(board[i][j]!=46) row[board[i][j] - '0']++; 
                }
                for(int x = 0 ; x < 10 ; x++){
                    if(row[x] > 1){
                        return false;
                    }
                }
                 row.assign(10, 0);
            }
            return true;
        }

        bool validCol(vector<vector <char>> &board){
             vector<int> col(10,0);
            for(int i = 0 ; i < 9 ; i++){
                for(int  j = 0 ; j < 9 ; j++){
                    if(board[j][i]!=46) col[board[j][i] - '0']++; 
                }
                for(int x = 0 ; x < 10 ; x++){
                    if(col[x] > 1){
                        return false;
                    }
                }
                 col.assign(10, 0);
            }
            return true;
        }
    bool isValidSudoku(vector<vector <char>> &board){
            //When the Whole Sudoku Box is Empty then also the Sudoku is a Valid Sudoku. 
             int blank = 0;
            for(int i = 0 ; i < 9 ; i++){
                for(int j = 0 ; j < 9 ; j++){
                    if(board[i][j]==46){
                        blank++;
                    }
                }
            }
            if(blank == 81) return true;
            //Will Make the call to Verify Row, Column, and the Box
            if(!validBox(board) || !validRow(board) || !validCol(board)) return false;
            return true;
        }
    //Time Complexity: O(9*9) + O(9*9*10) + ..... Ultimatley we can say that the Time Complexity is Constant.
    //Space Complexity: O(10)[FOR ROW VECTOR] + O(10)[FOR COLUMN VECTOR] + O(9)[FOR THE MAP]. 
};