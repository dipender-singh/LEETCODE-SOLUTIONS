//Floyd Warsahll Algorithm:- All Pair Shortest Path Algorithm
#include<bits/stdc++.h>
using namespace std;
const int N = 500;
int main(){
	int n,m;
	cin>>n>>m; //N is the number of nodes and M is the number of edges
	int dist[N][N];
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(i==j) dist[i][j]=0; // Because distance between the same node will be Zero not Infinity
			else dist[i][j]=INT_MAX; // Initially distance between i(first node) to j(second node) will be Infinity 
		}
	}
	//Now we will take Graph as the input
	for(int i = 0 ; i < m ; i++){  //There will be m number of edges in the graph
		int u ,v, weight;
		cin>>u>>v>>weight;
		dist[u][v] = weight; //Between two nodes will be a weight
	} 
	for(int k = 1 ; k <= n ; k++){  //First we will alow the inclusion of 1 node then we can allow 2 nodes and so on.... So this basically is for the level, that how many 
		                            //nodes we can include in between two nodes while calculating the shortest path between two nodes
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if (dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); //Now the shortest distance for the (k-1)th level is already calculated so for the kth level we will
				                                                      //just calculate the minimum value between the current distance and the path which is calculated by 
				}													  //including the (k)th level. 
			}
		}
	}
	return 0;
}
//Time Complexity:- O(N^3)
