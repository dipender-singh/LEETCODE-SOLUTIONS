class Solution {
public:
    /*Steps: 1.) We will find the Longest Increasing Path from every particular point in the matrix.
             2.)
             */
    
int dfs(int i , int j , int r , int c , vector<vector<int>>& matrix , vector<vector<int>>& visited, int p){
        if(i < 0 || j < 0 || i >= r || j >= c || matrix[i][j]<=p){
            return 0;
        }
    if(visited[i][j]!=0){
        return visited[i][j];
    }
    int t = dfs(i-1,j,r,c,matrix,visited,matrix[i][j]);
    int b = dfs(i+1,j,r,c,matrix,visited,matrix[i][j]);
    int le = dfs(i,j-1,r,c,matrix,visited,matrix[i][j]);
    int ri = dfs(i,j+1,r,c,matrix,visited,matrix[i][j]);
    visited[i][j] =  1+max(t,max(b,max(le,ri)));
    return visited[i][j];
    }

    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        
        int r = matrix.size();
        int c = matrix[0].size();
        
//We will move from one tile to another tile when that next tile will be greator than the current tile.
//Now this means that there are 'r' rows and each row have 'c' number of elements having value equal to false
        vector<vector<int>> visited(r, vector<int>(c,0)); 
        //Now we will try to implement DFS algorithm
        int ans  = 1;
        for(int i = 0 ;  i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                    ans = max (ans,dfs(i,j,r,c,matrix,visited,-1));
            }
        }
        return ans;
    }
};