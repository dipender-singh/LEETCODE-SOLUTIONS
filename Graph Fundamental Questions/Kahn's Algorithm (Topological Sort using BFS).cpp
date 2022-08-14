//Kahn's Algorithm : Topological Sort using BFS
vector<int> toposort(int V, vector<int> adj[]){
	vector<int> ans;
	//First we will create a vector which will store the in-degree's of all the nodes of the graph
	vector<int> indegree(V,0);
	for(int i = 0 ; i < V ; i++){
	for(auto it : adj[i]){
			indegree[it]++;
	}
}
	//Now we will take a queue
	queue<int> q;
	//We will first push all those nodes in our queue those who are having their in-degree's as zero (0)
	for(int i  = 0 ; i < V ; i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	//Now we know that those who are having their indegrees as zero will always be the first values of our topological sort and we will try to explore the
	//adjacent edges of these nodes who are having their indegrees as zero
	while(q.size()!=0){
		int current  = q.top();
		ans.push_back(current);
		q.pop();
		for(auto it : adj[current]){
			indegree[it] = indegree[it]-1;
			if(indegree[it]==0){
				q.push(it);
			}
		}
	} 
return ans;
}
