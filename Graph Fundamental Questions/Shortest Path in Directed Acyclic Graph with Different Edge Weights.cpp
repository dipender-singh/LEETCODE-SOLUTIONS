//Shortest Path in Directed Acyclic Graph with Different Edge Weights
//Now whenever we see a Directed Acyclic Graph there can be a possibility of TopoLogical Sorting
/*
Reason No: 1
Topological sort ensures that we are picking up nodes that come first while travelling from the source, this, in turn,
will ensure that every node will have at least one condition that it can be reached from the source.
As we are setting dist[src] = 0, it will start from there, the condition dis[node] != infinity will not let any  node other than src enter that condition first. 
Because of topological sort nodes coming before src will be discarded.

*/
/*
Reason No: 2
This problem, can be solved through BFS too.But there will be too many redundancies in it.
We start from source=0, it relaxes its adjacents, and pushes these adjacent nodes along with their distances into the queue.
Then these adjacent nodes will further relax their adjacent nodes and push the relaxed nodes.

Consider this graph: first of pair is the adjacent node and second of pair is the edge weight 

1->[(2,2), (3,1)]
2->(4,2)
3->(5,1)
5->(4,1)
4->(6,1)

Final queue will be like - (first of pair is the node and second of pair is the distance from source to this node)
(1,0)(2,2)(3,1)(4,4)(5 2)(6 5)(4 3)(6 4)
These all will be popped out when they relax their adjacent nodes.
For ex, (1,0) will be popped out before (2,2)(3,1) are pushed into queue and so on.

As we can see, there is redundancy, node 4 first came in the queue with a distance of 4 from source, and then again
node 4 came with a distance of 3 from the source, which increases time complexity, because, now (4,3) will have to again relax its adjacent nodes
to reduce the distances of its adjacent nodes.

So, if the pre-requisites of any node(say, cur) are relaxed as minimum as possible before the relaxation of node cur.Then
redundancy will never occur.
Taking the same example as above, if 1 2 3 5 are relaxed as minimum as possible before the relaxation of node 4. Then 
redundancy will never occur.

The solution to the above observation is Topological sort.
If we have Topo sort sequence, then we will take the source node first and relax its adjacent nodes.After that, we take next node
in the topo sort, and will do the same.
*/


void dfs(int i, stack<int> &st, vector<pair<int,int>> adj[], vector<bool> &visited){
	visited[i]=true;
	for(auto it : adj[i]){
		if(visited[it.first]!=true){
			dfs(it,V,adj,visited);
		}
	}
	st.push(i);//We push the node in the stack while doing Topo Sort when all the adjacent edges of that node have been visited
}

vector<int> shortest_path(int src, int V, vector<pair<int,int>> adj[]){ //Each Item will store the the node along with the edge weight of the Edge which is going out from that particular node
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<bool> visited(V,false);
    //First we will do the Topo Sort to get the Order of Nodes 
    stack<int> st;
    for(int i = 0 ; i < V ; i++){
    	if(visited[i]!=true){
    		dfs(i,st,adj,visited);
		}
	}
	//Now my Topo Sort is in the Stack and we have to find the Shortest Distance Possible from Source Node to every other node in the Graph
	vector<int> ans(V,INT_MAX);
	ans[src] = 0;
	while(st.size()!=0){
		int current = st.top();
		st.pop();
		if(ans[current]!=INT_MAX){ //We have reached the Node again
			for(auto it : adj[current]){
				if(ans[it.first] > ans[current]+it.second){
					ans[it.first] = ans[current]+it.second;
				}
			}
		} 
	}
} 

