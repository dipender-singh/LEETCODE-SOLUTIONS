class Solution {
public:
    
    void setintmin(vector<vector<int>>& matrix, int i , int j){
        //Here we will convert all the elements of that Row and Column to -1, and the elements which we are already Zero we 
        //will not change them, because their own Row and Column elements needs to be converted to zero.
        
        //i is the Row Number and j is the Column Number. 
        int n = matrix.size();
        int m = matrix[0].size();
        for(int x = 0 ; x < m ; x++){
            if(matrix[i][x]!=-9999 and matrix[i][x]!=0){
                matrix[i][x] = -9999;
            }
        }
        for(int y = 0 ; y < n ; y++){
            if(matrix[y][j]!=-9999 and matrix[y][j]!=0){
                matrix[y][j] = -9999;
            }
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0){
                    count++;
                    matrix[i][j] = -9999;
                    setintmin(matrix,i,j);
                }
            }
        }
        if(count!= 0){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == -9999) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    }
};