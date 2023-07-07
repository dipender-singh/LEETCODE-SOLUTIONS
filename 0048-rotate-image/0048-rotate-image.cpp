class Solution {
public:
    void rotate(vector<vector<int>>& matrix){
        
        /*
        Brute Force: Here we will use an Extra O(n*m) Matrix. 
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
        //Time Complexity : O(n*m) + O(n*m) = O(n*m)
        //Space Complexity : O(n*m) 
        */
        
        //Better Approach: 
        //Basically we have to do the Swapping of elements that's it. 
        
        //First i will do the Transpose of the Matrix.
        //Second i will reverse the elements of each row of the Matrix.
        int n = matrix.size();
        int m = matrix[0].size();
        
        //First will perform the Transpose of the Matrix.
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < m ; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //Now will reverse the elements of each row.
        int l = 0, h = m-1;
        for(int i = 0 ; i < n ; i++){ //This will help me to select each row
            //Will apply the Two-Pointer Approach to Reverse the Array. 
            while(l<h){
                swap(matrix[i][l],matrix[i][h]);
                l++;
                h--;
            }
            l = 0;
            h = m-1;
        }
    }
};