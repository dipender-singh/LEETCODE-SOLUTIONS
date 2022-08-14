//Shortest Path in an Undirected Graph with Unit Weights
//We have to find the Shortest Distance from the given Source Node to all other Nodes of the given Graph
vector<int> shortestpath(int source, int V ,vector<int> adj){
	vector<int> ans(V,INT_MAX); //This will store the shortest distance from Source Node to all other Node's
	queue<int> q;
	q.push(source);
	ans[source]=0;
	while(q.size()!=0){
		int i = q.front();
		q.pop();
		for(auto it : adj[i]){
			if(it!=source){
				int current = 1 + ans[i];
				if(current<ans[it]){
					ans[it]=current;
					q.push(it);
				}
	}
	}
}
return ans;
}
