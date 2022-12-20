class Solution {
public:
    
    void dfs(int i ,int n, vector<vector<int>>& rooms, vector<bool>& visited){
        if(visited[i]==false){
            //Now when a room is not visited, we will visit that room and mark it visited and will se that doees 
            //this room conatin the key to another room or not.
            visited[i]=true;
            for(auto it : rooms[i]){
                if(visited[it]==false){
                    dfs(it,n,rooms,visited);
                }
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //Try to think using Graphs using DFS.
        //Think like this when you enter a door see that do you have the key to the next door upon entering this 
        //particular door or not if not then just return false else continue the work.
        //Or it is just simple that we have to find that do we visit all the rooms or not.
        //In the end if there still remains a room which is not visited return false;
        
        int n = rooms.size(); //This is the total number of rooms
        vector<bool> visited(n,false);
        dfs(0,n,rooms,visited);
        for(int i = 0 ; i < n ; i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};