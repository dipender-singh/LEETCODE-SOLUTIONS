class Solution {
public:
    /*bool check(int i , int n, vector<int>& color, vector<int>& adj, queue<int>& q){
        color[i]=0;
        q.push(i);
        while(q.size()!=0){
            int current = q.front();
            q.pop();
            for(auto child : adj[current]){
                if(color[child] == -1){
                    if(color[current]==1){
                        color[child]=0;
                        q.push(child);
                    }
                    else{
                        color[child] = 1;
                        q.push(child);
                    }
                }
                else if(color[current] == color[child]) return false;
            }
        }
        return true;
    }
    */
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //Now think of this as a Graph coloring Problem
        vector<int> color(n+1,-1);
        // 0 means not colored
        //-1 means blue colored
        // 1 means green colored
        //Now to make the imagination easier we can convert the dislikes into a graph with starting edge of 0
        vector<int> adj[n+1];
        for(auto it : dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        //Will Apply BFS Logic
        for(int i = 1 ; i <= n ; i++){
            if(color[i]==-1){ //Means this node is not explored, so we will try to explore it
               color[i]=0;
        q.push(i);
        while(q.size()!=0){
            int current = q.front();
            q.pop();
            for(auto child : adj[current]){
                if(color[child] == -1){
                    if(color[current]==1){
                        color[child]=0;
                        q.push(child);
                    }
                    else{
                        color[child] = 1;
                        q.push(child);
                    }
                }
                else if(color[current] == color[child]) return false;
            }
        }
        
        }
    }
        return true;
    }
};