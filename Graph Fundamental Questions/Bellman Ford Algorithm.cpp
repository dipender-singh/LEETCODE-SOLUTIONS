//Bellman Ford Algorithm:- Single Source Shortest Path Algorithm
//Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph.
//The graph may contain negative weight edges. 

//Code:- 

struct node{
	int u;
	int v;
	int wt;
	
	node(int first, int second, int weight){
		u = first;
		v = second;
		wt = weight;
	}
};

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	//We will take graph as the input
	vector<node> edges;
	for(int i = 0 ; i < m ; i++){
		int u , v, weight;
		cin>>u>>v>>weight;
		edges.push_back(node(u,v,weight));
	}
	int source;
	cin>>source;
	
	vector<int> distance(n,INT_MAX);
	
	//Now will relax the given nodes for exactly N-1 times (N is the total number of Nodes)
	for(int i = 0 ; i < n-1 ; i++){
		for(auto it : edges){
			if(distance[it.u] + it.wt < distance[it.v]){
				distance[it.v] = distance[it.u] + it.wt;
			}
		}
	}
	
	//If after N-1 relaxations we again relax the edges one more time and the values stored in our distance vector reduces then we can say that for sure there is a -ve 
	//cycle in our graph
	bool cycle = false;
	for(auto it : edges){
		if(distance[it.u] + it.wt < distance[it.v]){
		        cout<<"Yes Cycle is there in the Graph"<<endl;
				cycle = true;
				break;
			}
	}
	return 0;
}

//Time Complexity for this is O(N-1)*O(E) because we are realxing E edges for N-1 times.
