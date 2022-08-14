
bool checkcycle(int starting_index, int V, vector<int> adj[], vector<bool> &visited){
	queue<pair<int,int>> q;
	q.push({starting_index,-1}); //It is assumed that our first node of every graph is '0' and it's parent is -1.
	visited[starting_index]=true;
	while(q.size()!=0){
		//Now we will try to explore all the adjacent nodes of the node which is at the top of our queue
		int current = q.front().first;
		int parent  = q.front().second;
		q.pop();
		//Now listen we have to mark a node as visited when we push it into the queue
		for( auto it : adj[current]){
			if(!visited[it]){ //If not visited then mark it visited and add it to the queue along it's parent that will be the current node
				visited[it]=true;
				q.push({it,current});
			}
			if(parent!=it){ //There is a node which has already been visited through some other node which is not a parent then we can say that there is a cycle
				return true;
			}
		}
		return false;
	}
}

bool iscycle(int V, vector<int> adj[]){
	visited<bool> (V,false);
	for(int i = 0 ; i < V ; i++){
		if(visited[i]!=true){
			if checkcycle(i,V,adj,visited) return true;
		}
	}
	return false;
}
