class Solution {
public:
    
    void dfs(int i, vector<vector<int>>& ans, vector<bool>& visited){
        visited[i]=true;
        for(auto j : ans[i]){
            if(!visited[j]){
                dfs(j,ans,visited);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //Graph Question: Easily Understood
        //First I will make a Graph
        vector<vector<int>> ans(n); //We will create an Adjacency List
        for(auto i : connections){
            ans[i[0]].push_back(i[1]);
            ans[i[1]].push_back(i[0]);
        }
        int components = 0;
        //Now for every Computer to be connected with each other we will need atleast (n-1) edges. 
        //If for example there are "n" computers we will need "n-1" edges.
        //And after doing lets say BFS/DFS we will be able to find the computers which are not connected. 
        vector<bool> visited(n,false);
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i,ans,visited);
                components++;
            }
        }
        int current_no_of_connections = connections.size();
        if(current_no_of_connections<n-1){
            return -1;
        }
        return components-1;
    }
};