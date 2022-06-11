class Solution {
public:
    /*BRUTE FORCE
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for(int i = 0 ; i < matrix.size() ; i++){ // no of rows
            for(int j = 0 ; j < matrix[0].size() ; j++){ // no of columns
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
        */
    bool do_binary(vector<vector<int>>& matrix ,int row , int target){
        vector<int> ans;
        for(int col = 0 ; col < matrix[0].size() ; col++){ //O(N)
            ans.push_back(matrix[row][col]); //O(N) EXTRA SPACE
        }
        int l = 0;
        int r = ans.size()-1;
        while(l<=r){ //O(logN)
            int mid = (l+r)/2;
            if(ans[mid]==target){
                return true;
            }
            else if(ans[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
    }
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        bool ans=false;
        int n = matrix[0].size();
        for(int i = 0 ; i < matrix.size(); i++){ //O(N)
                if(matrix[i][0]<=target and matrix[i][n-1]>=target){
                     ans = do_binary(matrix,i,target);
                }
        }
        return ans;
    }
};