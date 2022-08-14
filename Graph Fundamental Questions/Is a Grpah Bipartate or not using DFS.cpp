 //Is a Graph Bipartate or not using DFS
 bool check(int s, int V, vector<int> &color, vector<vector<int>> &graph){
        if(color[s]==-1) color[s]=1;
        for(auto it : graph[s]){
            if(color[it]==-1){
                color[it]=1-color[s];
                if(check(it,V,color,graph)==false) return false;
            }
            else if(color[it]==color[s]) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int V = graph.size();
        vector<int> color(V,-1);
        bool ans = true;
        for(int i = 0 ; i < V ; i++){
            if(color[i]==-1){
                if(!check(i,V,color,graph)) return false;
            }
        }
        return ans;
    }
