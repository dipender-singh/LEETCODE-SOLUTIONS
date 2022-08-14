#include<bits/stdc++.h>
using namespace std;
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	vector<int> adj[nodes]; //Now this means that we have created a 1-D array for each node to store the nodes which form edges with this particular node
	//Now how many times we will run the loop, we will run the loops jitni hume edges chahiye
	//apne graph mein
	for(int i = 0 ; i < edges; i++){
		int u,v;
		cin>>u>>v; // U stands for the first node  and V stands for the second node,
		           // these are the nodes between whom we want an edge
		adj[u].push_back(v);
		adj[v].push_back(u); 
	}
	for(int i = 0 ; i < nodes ; i++){
		cout<<i<<" ";
		int x = adj[i].size();
		for(int j = 0 ; j < x; j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
	//Space Complexity is O(N+2E) because for every node we are storing 2 edges
}
