//Topological Sort using DFS

void dfs(int s, vector<bool> &visited,vector<int> adj[], vector<int> &ans, stack<int> &st){
	visited[s]=true;
	for(auto it : adj[s]){
		if(visited[it]!=true){
			dfs(it,visited,adj,ans,st);
		}
	}
	st.push(s);
}

vector<int> topo(int V, vector<int> adj[]){
	//Always take visited vector as a boolean because a boolean variable takes 1 byte and integer variable take 4 bytes
	vector<bool> visited(V,false);
	vector<int> ans;
	stack<int> st;
	for(int i = 0 ; i < V ; i++){
		if(visited[i]==false){
			dfs(i,visited,adj,ans,st);
		}
	}
	while(st.size()!=0){
		auto it = st.top();
		ans.push_back(it);
		st.pop();
	}
	return ans; 
}


