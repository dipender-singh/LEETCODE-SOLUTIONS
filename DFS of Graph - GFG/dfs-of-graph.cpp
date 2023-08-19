//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(stack<int>& st, vector<bool>& visited, vector<int>& ans, vector<int> adj[]){
        int curr = st.top();
        st.pop();
        ans.push_back(curr);
        for(auto it : adj[curr]){
            if(visited[it] == false){
                visited[it] = true;
                st.push(it);
                dfs(st,visited,ans,adj);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        stack<int> st;
        vector<int> ans;
        visited[0] = true;
        st.push(0);
        dfs(st,visited,ans,adj);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends