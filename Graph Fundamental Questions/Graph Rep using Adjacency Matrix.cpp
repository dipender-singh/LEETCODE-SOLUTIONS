#include<bits/sdtc++.h>
using namespace std;
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	int adj[nodes+1][nodes+1];
	memset(adj,0,sizeof(adj));
	//Now how many times we will run the loop, we will run the loops jitni hume edges chahiye
	//apne graph mein
	for(int i = 0 ; i < edges; i++){
		int u,v;
		cin>>u>>v; // U stands for the node 1 and V stands for the second node, these are
		           // the nodes between whom we want an edge
		adj[u][v]=1;
		adj[v][u]=1; 
	}
	for(int i = 0 ; i < nodes ; i++){
		for(int j = 0 ; j < nodes ; j++){
			cout<<adj[i][j];
		}
		cout<<endl;
	}
	return 0;
}

