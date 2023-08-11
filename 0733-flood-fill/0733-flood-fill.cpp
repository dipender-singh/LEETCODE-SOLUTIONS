class Solution {
public:
    
    void helper(vector<vector<int>>& image, int i, int j, int color, int st){
        if(i < 0 || j < 0 || i >= image.size() || j >=image[0].size() || image[i][j] != st){
            return;
        }
        if(image[i][j] == st){
            image[i][j] = color;
            helper(image,i+1,j,color,st);
            helper(image,i-1,j,color,st);
            helper(image,i,j+1,color,st);
            helper(image,i,j-1,color,st);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //Brute Force
        //Using DFS
        int st = image[sr][sc];
        if(st != color){
        helper(image,sr,sc,color,st);
        }
        return image;
    }
};