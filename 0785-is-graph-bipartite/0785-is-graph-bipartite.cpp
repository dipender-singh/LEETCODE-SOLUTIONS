class Solution {
public:
    
    bool dfs(int node, int curr_state, vector<pair<bool,int>>& vis, vector<vector<int>> graph){
        vis[node].first = true;
        curr_state = curr_state % 2;
        vis[node].second = curr_state; 
        bool ans = true;
        curr_state++;
        for(auto it : graph[node]){
            if(vis[it].first == false){
                ans = dfs(it,curr_state,vis,graph);
                if(ans == false){
                    return false;
                }
            }
            else if(vis[it].first == true){
                if(vis[it].second == vis[node].second){
                    cout<<"Parent Node :"<<node<<" and State of Parent Node is :"<<vis[node].second;
                    cout<<"Child Node :"<<it<<" and State of Child Node is :"<<vis[it].second;
                    return false;
                }
            }
        }
        return ans;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        //Given that it is a Graph Question 
        //I can see that it is a Simple DFS
        //Components are there, and the Graph is also Undirected. 
        int n = graph.size();
        vector<pair<bool,int>> vis(n, {false,0});
        bool ans = true;
        for(int i = 0 ; i < n ; i++){
            if(vis[i].first == 0 && graph[i].size() != 0){
                if(dfs(i,0,vis,graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};