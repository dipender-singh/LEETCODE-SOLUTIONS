class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Brute Force:
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans;
        vector<int> curr;
        for(int i = 0 ; i < m ; i++){
            for(int j = n-1 ; j >=0 ; j--){
                curr.push_back(matrix[j][i]);
            }
            ans.push_back(curr);
            curr = {};
        }
        //Now we will copy all the values of the ans vector to the Matrix vector.
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};