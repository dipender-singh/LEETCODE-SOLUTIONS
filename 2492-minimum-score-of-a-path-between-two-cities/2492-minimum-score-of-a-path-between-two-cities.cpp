class Solution {
public:
    
    int minScore(int n, vector<vector<int>>& roads) {
//We can do a simple DFS becuase we just have to find the smallest edges weight between the Start Node 
//the Destination Node and we can visit any edge multiple Number of times so we just have to do DFS, with DFS  
//we will travel on each and every edge between all the nodes in the whole graph and we will get out smallest 
//possible weight edge which will ultimatley be our answer.
        
        //Brute Force:
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto node : roads){
            graph[node[0]].push_back({node[1],node[2]});
            graph[node[1]].push_back({node[0],node[2]});
        }
        //Time Complexity: O(N + 2E + 2W) //E-> Edge and W-> Weight
        //We can do DFS or BFS anything. 
        
        //I will try to implement BFS here.
        vector<bool> visited(n+1,false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int ans=INT_MAX;
        while(q.size()!=0){
            int curr = q.front();
            q.pop();
            for(auto& [v,dis] : graph[curr]){
                ans=min(ans,dis);
                if(visited[v]==false){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        return ans;
    }
};