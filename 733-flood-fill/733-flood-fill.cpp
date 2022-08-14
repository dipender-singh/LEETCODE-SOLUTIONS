class Solution {
public:
    
    void helper(int i, int j, int r, int c, vector<vector<int>>& image, int color, int target){
        if(i<0 || j<0 || i>=r || j>=c){
            return;
        }
        else if(image[i][j]!=target){
            return;
        }
        else if(image[i][j]==target){
            image[i][j]=color;
        }
        //Now explore all the four sides of the current position
        helper(i+1,j,r,c,image,color,target);
        helper(i-1,j,r,c,image,color,target);
        helper(i,j+1,r,c,image,color,target);
        helper(i,j-1,r,c,image,color,target);
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int r = image.size();
        int c = image[0].size();
        int target = image[sr][sc];
        //If starting pixel and given color are different then only we have to do our operations
        if(target!=color){
        helper(sr,sc,r,c,image,color,target);
        }
        return image;
    }
};