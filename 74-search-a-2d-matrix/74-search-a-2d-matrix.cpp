class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //brute force
        ios_base::sync_with_stdio(0); 
        cin.tie(0);cout.tie(0);
        bool ans = false;
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(matrix[i][j]==target){
                    ans = true;
                }
            }
        }
        return ans;
    }
};