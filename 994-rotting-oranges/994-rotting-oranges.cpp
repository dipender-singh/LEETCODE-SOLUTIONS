class Solution {
public:
    
    vector<int> dr = {1,0,-1,0};
    vector<int> dc = {0,1,0,-1};
    
    bool isvalid(int i , int j , int r , int c , vector<vector<int>> &grid,int &one){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==2 || grid[i][j]==0){
            return false;
        }
            grid[i][j]=2;
            one--;
            return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //Will not be able to use dfs because it can or will give stack overflow error here so will use bfs
        //First will find a rooten orange and will store it's indices
        int r = grid.size();
        int c = grid[0].size();
        int one = 0;//Represent Fresh Oranges
        int two = 0;//Represent Rotten Oranges
        queue<pair<int,int>> q;
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    two++;
                }
                if(grid[i][j]==1){
                    one++;
                }
            }
        }
        if(one==0){
            return 0;
        }
        if(two==0){
            return -1;
        }
        //Now will perform BFS over the grid using the queue
        int ans = 0;
        while(q.size()!=0){
            int l = q.size();
            while(l--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int e = 0 ; e < 4 ; e++){
                if(isvalid(x+dr[e],y+dc[e],r,c,grid,one)) q.push({x+dr[e],y+dc[e]});
                    }
            }
            ans++;
        }
        if(one!=0){
            return -1;
        }
        return ans-1;
    }
};