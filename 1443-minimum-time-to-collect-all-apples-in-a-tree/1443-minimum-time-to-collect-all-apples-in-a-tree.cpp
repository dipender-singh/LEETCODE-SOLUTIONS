class Solution {
public:
    
    
    void graph(vector<vector<int>>& edges, vector<int> adj[]){
        //Now we will iterate over the given 2-d array and will convert that particular 2-D Array to a Graph 
        //using the concept of adjacency list.
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    }
    
    int dfs(int start, int par, vector<bool>& hasApple, vector<int> adj[]){
        //So basically what we will be doing is that we at every node will see that from this node what value of 
        //time we will be sending back upwards (if we see the graph as a tree) from this particular node.
        
        //Now whenever we encounter an apple we return saomething now for example see the first example and 
        //notice that when we go to node 4 we see that there is an apple there and what we do is we return a 
        //value because when we go from 1 to 4 we took one second and when we encountered an apple at node 4 we 
        //took that apple and move to node 1 so same will be for node 5 so from every node that is from node4 
        //and node5 we are returning value of +2 (1 for reaching to that node and from going to the parent node 
        //from that node).
        //And this is how we will figure out that the child node of a partiuclar node is having any children 
        //with apple or not, if not then we will be returning a zero value.
        
        //Code:- Will be applying the DFS Approach Since i am not performing Recursion here so will have to keep 
        //a visited array or a map also in order to prevent visiting the same nodes again and again.
        
        int cost = 0;
        for(auto neigh : adj[start]){
            if(neigh == par){ //Now parent is the node from where we come so it will be already visited and so 
                              //if the node which is the neighbour of the current is the parent node itself then 
                              //we will not explore that node again
                continue;
            }
            cost = cost + dfs(neigh,start,hasApple,adj);
        }
        if(hasApple[start] == true || cost>0){
            cost = 2+cost;
        }
            return cost;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        // 1 second is spent to walk over one edge of the tree
        // return the minimum time to spend to collect all the apples in the tree
        //start from vertex 0 and then come back to this starting node
        
        //Think this not as a Tree think of it as a Graph only visulization becomes a bit easier
        int start = 0;
        //For better understanding this problem as a graph problem convert the 2-d array to the adjacency list
        vector<int> adj[n];//We have basically created a adjacency list
        graph(edges,adj);
        int ans = dfs(0,-1,hasApple,adj);
        if(ans>0){
            return ans-2;
        }
        return ans;
    }
};