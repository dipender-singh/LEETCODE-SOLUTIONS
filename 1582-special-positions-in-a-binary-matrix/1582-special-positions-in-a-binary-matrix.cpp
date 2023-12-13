class Solution {
public:
    
    bool helper(int i, int j, vector<vector<int>>& mat){
        //We have to look in the (i)th Row
        //We have to look in the (j)th Column
        bool ans = true;
        for(int x = 0 ; x < mat[0].size() ; x++){
            if(mat[i][x] == 1 and x!=j){
                ans = ans & false;
            }
        }
        
        for(int x = 0 ; x < mat.size() ; x++){
            if(mat[x][j] == 1 and x!=i){
                ans = ans & false;
            }
        }
        return ans;
    }
    
    int numSpecial(vector<vector<int>>& mat) {
        //Brute Force
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 1){
                    //Then now we have to look in all the four directions of it.
                    if(helper(i,j,mat) == true){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};