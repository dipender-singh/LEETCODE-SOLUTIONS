//Check Cycle in Undirected Graph using DFS

bool check(int current, int parent,int V, vector<bool> &visited, vector<int> adj[]){
	visited[current]=true;
	for(auto it : adj[current]){
		if(!visited[it]){
			bool c = check(it,current,V,visited,adj);
			if(c == true){
				return true;
			}
		}
		else if(it!=parent){
			return true;
		}
	}
	return false;
}

bool cycleDFS(int V, vector<int> adj[]){
	vector<bool> visited(V,false);
	for(int i = 0 ; i < V ; i++){ //For selecting the components
		if(!visited[i]){
			if(check(i,-1,V,visited,adj)) return true;
		}
	}
	return false;
}

