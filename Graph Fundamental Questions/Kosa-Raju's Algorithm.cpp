//Kosa-Raju's Algorithm
//https://www.topcoder.com/thrive/articles/kosarajus-algorithm-for-strongly-connected-components
//For Strongly Connected Components
//Now Strongly Connected Components means that if we start from a Node, then we can reach to all other nodes of that Component in the Graph.
/*Working:-
1.) Sort all the nodes in order of finishing time. For this we will use Topo Logical Sort because Topo Sort gives the sequence of nodes in such a way that the first node
in the sequence is the node which do not have any incoming edge and can't be visited by any other node or we can say that it gives the nodes which will be visited at the  
last in the beginning of our Topo Sort sequence. Now since Topo Sort is doing a DFS traversal so it's TC will be O(V+E).
What topo sort like thing does is:
It arranges all the nodes of the directed graph in the order of decreasing out time from top to bottom in the stack(i.e, st.top() has the highest out time node)
And why we are doing so?
So that our dfs call on the node extracted from the stack will be restricted to its own SCC and the total number of dfs calls from the main() function
on the transposed graph will be exactly equal to the number of SCC in the given directed graph.

2.) Transpose the Graph. Such that all the edges of the graph become reversed in the direction opposite to the initial direction of edges of the graph. Now transposing
is like a traversal of the graph so it's TC will be O(V+E).

3.) Do DFS according to the finishing time. Now we are again doing a DFS here so another O(V+E).

Space Complexity will be O(V) for visited array, O(V) for a stack for doing Topo Sort, O(V+E) for storing the Transposed Graph.

*/

//Code:-

void dfs(int start, int V, vector<bool> &visited, vector<int> adj[]){
	visited[start] = true;
	cout<<start<<" ";
	for(auto it : adj[start]){
		if(visited[it]!=true){
			dfs(it,V,visited,adj);
		}
	}
}

void topo_sort(int start, int V, vector<bool> &visited, stack<int> &st,vector<int> adj[]){
	visited[start]=true;
	for(auto it : adj[start]){
		if(visited[it]!=true){
			dfs(it,V,visited,st,adj);
		}
	}
	//After exploring all the edges of a node, or if a node do not have any adjacent edges we will push that node in to our stack
	st.push(start);
}

int main(){
	//Will take the directed Graph as the input
	int n,m;
	cin>>n>>m; // N is the nodes and M is the edges
	vector<int> adj[n]; //Adjacency List for storing the adjacent nodes for N nodes in the graph
	for(int i = 0 ; i < m ; i++){ //Graph will have M number of edges
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	//Now we will find the Topo Sort of the graph in the stack
	stack<int> st;
	vector<bool> visited(V,false);
	for(int i = 0 ; i < V ; i++){
		if(visited[i]==false){
			topo_sort(i,V,visited,st);
		}
	}
	//Now our Stack has all the Nodes in order of their finishing time
	
	//Now we will Transpose our Graph
	vector<int> transpose[n]; 
	for(int i = 0 ; i < n ; i++){
		visited[i]=false;
		for(auto it : adj[i]){
			trasnpose[it].push_back(i);
		}
	}
	
	//Now we will do the DFS of the elements stored in our stack to get our Sequence of the Strongly Connected Components
	while(st.size()!=0){
		int current = st.top();
		st.pop();
		if(visited[current]!=true){
			cout<<"Strongly Connected Components "
			dfs(i,V,visited,transpose);
			cout<<endl;
		}
	}
	return 0;
}
