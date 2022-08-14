//Prim's Algorithm

vector<int> prims(int V, vector<pair<int,int>> adj){
	
	/*First of all we will take 3 vector's which will tell us 3 different concepts
	1.) First vector will be a key vector which will basically store the cost to reach to a particular index node (Vector Name: key)
	2.) Second vector will be a boolean vector which will help us to keep a track of a particular index node that is it a part of the MST or not (Vector Name: MST)
	3.) Third vector will be a parent vector which will store the parent of every node (Vector Name: parent)
	
	
	Now the cost to reach the starting node will obviously be zero, so we will pick up the starting node and will make it a part of the mst and for this we will mark it true
	in the boolean vector.
	And now we will try to explore the adjacent nodes of this starting node which are not a part of our MST and we will update the cost of reaching to them from the starting 
	node (only if the current cost which is calculated is less than the previously calculated cost)
	Now we will update their cost and will also update their parent in the parent array.
	Now for selecting the second node which we shall explore we will ietrate over the key array and will pickup that node which has the smallest key value and will mark as 
	true because it will now be a part of our MST and then we will repeat the whole above process again
	*/ 
	
	vector<bool> MST(V,false);
	vector<int> parent(V,-1);
	vector<int> key(V,INT_MAX);
	//We will be given a starting node, if not we will assume the starting node of the graph to be Node:- 0
	key[0]=0;
	for(int i = 0 ; i < V-1 ; i++){  //For V-1 edges because our MST have exactly V-1 edges
		int mini = INT_MAX, u;
		//Now we will basically iterate over the key array to find the node with the minimum cost and which is not a aprt of our MST
		for(int k = 0 ; k < V ; k++){
			if(MST[k]==false && key[k]<mini){
			//Now if we have found such node then we will iterate over the adjacent nodes of this particular node and will try to explore those nodes which are not a part
			//of the MST and try to find the cost to reach to these adjacent nodes, if the cost calculate now is less than the previous cost for those nodes
			//then we will update their cost in the key array
			u = k;
			mini = key[k];
			//Now we will explore the adjacent nodes which are not a aprt of the MST
			for(auto it : adj[u]){
				int x = it.first;
				int weight = it.second;
				if(MST[x]== false && key[x] > weight){
					parent[x] = u;
					key[x] = weight;
				}
			}
			}
		}
	}
}

//Time Complexity is O(N^2) because we will go through N nodes for (N-1) times.
//Can further optimize using a MIN Priority Queue and then Time Complexity will be O((V+E)logV)
