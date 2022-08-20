class Solution {
public:

        map<string,vector<pair<string,double>>> mp;
    
    double bfs(string o , string t){
        //Now BFS requires a Queue and a Visited Array
        string src = o;
        string dest = t;
        queue<pair<string,double>> qe;
        unordered_set<string> visited;
        qe.push({src,1});
        visited.insert(src);
        while(qe.size()!=0){
            auto it = qe.front(); //Now this 'it' operator will point to a whole pair which was stored at the 
                                  //front of the queue
            
            if(it.first == dest){
                return it.second;
            }
            qe.pop();
            for(auto itt : mp[it.first]){
                if(visited.find(itt.first)==visited.end()){
                    //Now if the adjacent node of the current node is not visited we will add it to the queue
                    //and will mark it visited
                    qe.push({itt.first,itt.second * it.second});
                    visited.insert(itt.first);
                }
            }
        }
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //Take Graph as Input
        for(int i  = 0 ; i < e.size() ; i++){
            string none = e[i][0];
            string ntwo = e[i][1];
            double val = v[i];
            mp[none].push_back({ntwo,val});
            mp[ntwo].push_back({none,double(1/val)});
        }
        //Vector to store the values for the given queries
        vector<double> result;
        for(auto it : q){ //Now we will iterate over the queries vector 
            string o = it[0];
            string t = it[1];
            if(mp.find(o)==mp.end() || mp.find(t)==mp.end()){ 
                //If any one of the node is not present then we can't 
                //find it's distance, then in that case we will just push -1 in the array.
                result.push_back(-1);
                continue;
            }
            result.push_back(bfs(o,t));
        }
        return result;
    }
};