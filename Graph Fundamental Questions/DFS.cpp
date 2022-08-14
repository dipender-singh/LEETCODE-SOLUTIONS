void dfs(int start, int V, vector<int> adj[], vector<bool> &visited, vector<int> &ans){
	ans.push_back(start);
	visited[start]=true;
	for(auto it : adj[start]){ //Now we have selected a node so we will go from that node to all it's children node and then will explore it's all the children
	                           //and will keep on going to explore the children's children (which basically means we will keep on going into the depth of a node)
		if(visited[it]!=true){
			dfs(it,V,adj,visited,ans);
		}
	}
}


vector<int> DFS(int V, vector<int> adj[]){
	//We have to perform the DFS of the graph
	vector<bool> visited(V,false);
	vector<int> ans;
	for(int i = 0 ; i < V ; i++){ // First we will select a node in the graph and will do dfs from there
		if(visited[i]!=true){
			dfs(i,V,adj,visited,ans);
		}
	}
}
