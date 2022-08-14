 //Is a Graph Bipartate or not using BFS
bool check(int start, int V, queue<int> &q , vector<int> &color,vector<vector<int>> &graph){
 	q.push(start);
 	color[start]=0;
 	while(q.size()!=0){
     	int current = q.front();
     	q.pop();
     	for(auto child : graph[current]){
     		if(color[child]==-1){ //If the child is not visited
     			if(color[current]==0){ //If parent is of color 0
     				color[child]=1;
                    q.push(child);
				 }
				 else if(color[current]==1){ //If parent is of color 1
     				color[child]=0;
                     q.push(child);
				 }
			 }
			 else if(color[current]==color[child]) return false; //If for the current node there exists an 
                                                              //adjacent node of this current node which 
                                                              //already has the same color
		 }
	 }
	 return true;
 }
 
 bool isBipartite(vector<vector<int>>& graph){
 	 ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);
     int V = graph.size(); //This will give the number of nodes in the graph
     vector<int> color(V,-1); //There will be only two colors 0(First Color) and 1(Second Color)
     queue<int> q; //This will help us to store the nodes while doing BFS
     //We will try to do BFS Traversal
     for(int i = 0 ; i < V ; i++){ //For Selecting the Components
         if(color[i]==-1){ //For selecting only those components which are not visited yet
     if(!check(i,V,q,color,graph)) return false;
         }
 }
 return true;
    }
