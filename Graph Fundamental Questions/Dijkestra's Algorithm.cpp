//Dijkestra's Algorithm
//Here given a graph and a source vertex in the graph, find the shortest paths from the source to all vertices in the given graph.
//But here in this question we will be finding the shortest path in an undirected graph from source to all other nodes in the graph
//What we are doing here is we are performing things in greedy manner means that we are going to select the smallest edge weight which is connected to our current
//node (at which we are standing right now).
typedef pair<int,int> pa;
vector<int> dijkestra(int source, int V, vector<pair<int,int>> adj[]){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //Since we are exploring only that edge which is requiring lowest distance or lowest cost of exploring so for that we will use a min priority queue
    //In C++ STL by default we have a max priority queue
    //priority_queue<int> pq; is a max priority queue
    priority_queue<pa, vector<pa>, greater<pa>> pq;  //This is a Min Priority Queue which will store the node along with the distance
    pq.push({source,0});
    vector<int> ans(V,INT_MAX);
    ans[source] = 0;
    while(pq.size()!=0){
    	int node = pq.top().first;
    	int dist = pq.top().second;
    	pq.pop();
    	for(auto it : adj[node]){
    		if( dis + it.second < ans[it.first]){
    			ans[it.first] = dis + it.second;
    			pq.push({it.first,ans[it.first]});
			}
		}
	}
	return ans;
}
//Time Complexity = O((V+E)logV) // V is the number of Node's in the Graph, logV because of the Priority Queue
//Space Complexity = O(V) // V is the number of Node's in the Graph, we are using a Priority Queue and a Distance Array

