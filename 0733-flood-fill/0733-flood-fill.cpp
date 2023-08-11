class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //BFS
        //Using Queue
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        int st = image[sr][sc];
        if(st!=color){
            q.push({sr,sc});
            while(q.size()!=0){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i<0 || j<0 || i >= n || j >= m || image[i][j]!=st){
                    continue;
                }
                if(image[i][j] == st){
                    image[i][j] = color;
                    q.push({i+1,j});
                    q.push({i-1,j});
                    q.push({i,j+1});
                    q.push({i,j-1});
                }
            }
        }
        return image;
    }
};