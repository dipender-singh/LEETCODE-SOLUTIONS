//Kruskal's Algorithm:- To create an MST
//Pre-Requisites: Disjoint Set
//Kruskal's Algorithm is used to find the minimum spanning tree for a connected weighted graph.
//The main target of the algorithm is to find the subset of edges by using which we can traverse every vertex of the graph.
//It follows the greedy approach that finds an optimum solution at every stage instead of focusing on a global optimum.

/*Working Steps:-
1.) Sort all the edges on the basis of weights and add them into a linear data strucutre
2.) Then following the Greedy Approach we will pick up the edge which has the lowest weight.
3.) Then the edges we have pciked up will have two nodes associated with it let them be u and v. Now we have to check that if u and v belongs to the same component or not
    using the Disjoint Set Data Structure. Now if they don't belong to the same component then that edge will be included in our MST.
    We are checking that two nodes don't belong to the same component because our MST can not have cycles, so to avoid the occurences of cycles in our MST we are doing or
	performing this particular check. This is where Dis Joint Set will help us we will find the parent of the two nodes if both of the nodes have the smae parent then
	we can say that they belong to the same component.
*/

#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N=5,m=6;
	vector<node> edges; 
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
	sort(edges.begin(), edges.end(), comp); //Sorting the edges in the increasing order of weight using a comparator function.
	
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; 
	vector<int> rank(N, 0); 
	
	int cost = 0;
	vector<pair<int,int>> mst; 
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {  //We will attach two nodes when they belong to different components
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); //We are including the edge in our MST so we will have to do Union of the two components
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}

//Time Complexity:- O(nlogn)+O(alpha(n)) this approximately becomes equal to O(nlogn)
