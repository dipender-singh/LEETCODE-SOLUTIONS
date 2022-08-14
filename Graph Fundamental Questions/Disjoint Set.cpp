/*Dis-Joint Set Union Algorithm: Union by Rank and Path Compression
A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.
A union-find algorithm is an algorithm that performs two useful operations on such a data structure:

1.) Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
2.) Union: Join two subsets into a single subset. Here first we have to check if the two subsets belong to same set. If no, then we cannot perform union.

Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not.



DisJoint Set Data Sructure has two functions namely FindParent() and Union().
1.) FindParent() function does the operation, it helps us to find the parent of a component to which a particular node belongs. For example we are taking a Node-1 and Node-1
is the parent of the Node-1 itself. So, Node-1 is a component itself. So we can say Node-1 is itself a parent and child also. So, if we apply the FindParent() function on the
Node-1 itself it is going to return us Node-1.
2.) Union() funtion does the operation, Now let's suppose we have two components first compnent in which we have nodes from number 1 to 5 and second component in which we 
have nodes from number 6 to 10, and now we are performing the function Union(2,6). Now the function Union(2,6) will combine both the compnents which Node 2 and Node 6
are part of.

Now upon combining the two different components through Union then we will also have to change the parents of the nodes in the new combined component, which is combined using 
Union function. 

Working: We will take a parent array which will store the parent of each node, initially every node will be the parent of itself.
And we will make a rank array, initially the rank of every node will be 0.

Now while doing Union when two nodes have parent's as themselves and both of the nodes whose Union we have to do have the same Rank then we can attach anyone to anyone.
*/
//Suppose we have V nodes

int findparent(int node,vector<int> &parent){
	if(node == parent[node]){ //If parent of the node is the node itself
		return node;
	}
	//We will find the parent of the node
	/*return findparent(parent[node],parent);  This particular line does not represnt path compression*/
	return parent[node] = findparent(parent[node],parent);//This particular line represents path compression
}

void union(int u , int v, vector<int> &rank){
	//Before doing union we have to find the parent of the nodes u and v and their rank's also
	u = findparent(u);
	v = findparent(v);
	if(rank[u] < rank[v]){
		parent[u] = v;
	}
	else if(rank[v] < rank[u]){
		parent[v] = u;
	}
	else if(rank[u]==rank[v]){
		//If both have the same rank then we can anyone to anyone
		parent[v] = u;
		rank[u]++;
	}
}

int disjoint(int V, vector<int> adj[]){
	//We will be provided with a graph
	vector<int> rank(V,0); // Initially Rank of every node will be 0
	vector<int> parent;
	for(int i = 0 ; i < V ; i++){ //Initially parent of every Node will be that Node itself
		parent.push_back(i);
	}
	//Then while doing the Union of Two Components we will be finding the Parents of the nodes for whom we are doing the Union
	
	//If we are performing our function for m number of times
	int m;
	cin>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		union(u,v);
		//To see if Two nodes belong to the same component or not
	if(findparent[u]!=findparent[v]){
		cout<<"Does not belongs to the same component"<<endl;
	}
	else{
		cout<<"Belongs to the same component"<<endl;
	}
	}
}

//Time Complexity: O(4) , it's having a Constant Time Complexity.
