//Cycle Detection in Directed Graph using BFS (Kahn's Algorithm)
bool cycle(int V , vector<int> adj[]){
	//We will be using BFS technique and Kahn's Alogrithm to solve this problem
	//Since it has to be done using Kahn's Algorithm so it has to do something with indegrees of the nodes of the graph
	//Kahn's Algo was only applicabe to Directed Acyclic Graph and not applicable to Cyclic Graph (Intution)
	//So in the indegree vector if after doing all the calculations of the queue we observed that there is still an element in the queue whose indegree is still
	//not equal to zero this means that our Graph has a cycle, if all the nodes indegrees have become equal o Zero then this means that the cycle does not have
	//a cycle in it.
	
	/*Logic Explanatition : Okay so to clarify the (cnt == N) logic. Although it was a great explaination.
In Kahn's algorithm, a node only enters the queue if its indegree becomes zero and then it further decrements the indegree values of its adjacent nodes right. 
But in the case of cyclic graph , there will be a node from where the cycle will be starting and then coming to an end. 
So in order for the elements present in the cycle to get pushed into the queue, that cycle starting node's indegree must become zero right.
But but but, that node's indegree will never become zero as one of the node from the cycle (the second last element) will be pointing towards the starting node. 
Just imagine with a diagram in the video. 
So if that node's indegree will never become zero , then it will restrict its adjacent nodes(at least) 
to get evaluated and hence the total number of nodes getting pushed into the queue (cnt) will never become (=N).*/
	vector<int> indegree(V,0);
	for(int i = 0 ; i < V ; i++){
		for(auto it: adj[i]){
			indegree[it]++;
		}
	}
	queue<int> q;
	for(int i = 0 ; i < V ; i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	while(q.size()!=0){
		int current = q.front();
		int q.pop();
		for(auto it : adj[current]){
			indegree[it]-=1;
			if(indegree[it]==0){
				q.push(it);
			}
		}
	}
	for(int i = 0 ; i < V ; i++){
		if(indegree[i]!=0){
			return true;
		}
	}
	return false;
}
