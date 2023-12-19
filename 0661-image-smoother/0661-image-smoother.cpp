class Solution {
public:
    
    int helper(int i, int j, vector<vector<int>>& img){
    //Run a For Loop for 3*3 Combinations of i and j and just ignore where the looping variables becomes equal to the
    //passed value of i and j. 
        int count = 0;
        int sum = 0;
        for(int x = -1 ; x < 2 ; x++){
            for(int y = -1 ; y < 2 ; y++){
                int newRow = i + x;
                int newCol = j + y;
                if(newRow >= 0 and newRow < img.size() and newCol >= 0 and newCol < img[0].size()){
                    count++;
                    sum = sum + img[newRow][newCol];
                }
            }
        }
        return floor(sum/count);
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans[i][j] = helper(i,j,img);
            }
        }
        return ans;
    }
};