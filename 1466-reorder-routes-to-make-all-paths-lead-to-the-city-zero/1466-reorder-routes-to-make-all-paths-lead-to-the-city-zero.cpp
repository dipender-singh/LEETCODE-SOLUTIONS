class Solution {
public:
    
    void dfs(int curr, int parent, unordered_map<int,vector<pair<int,bool>>>& graph, int& ans){
        for(auto it : graph[curr]){
            int p = it.first;
            int check = it.second;
            
            //To prevent going and checking the parent node again
            if(p!=parent){
                if(check == 1){
                    //This means that the node is from source to destination and we have to reverse this node.
                    ans++;
                }
                dfs(p,curr,graph,ans);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        unordered_map<int,vector<pair<int,bool>>> graph;
        for(auto it : connections){
            graph[it[0]].push_back({it[1],1}); //This means that this is the original edge
            graph[it[1]].push_back({it[0],0}); //This means that this edge is added by me.
        }
        int ans = 0;
        dfs(0,-1,graph,ans);
        return ans;
    }
};