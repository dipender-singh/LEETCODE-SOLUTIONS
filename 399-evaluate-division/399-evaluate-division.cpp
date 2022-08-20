//First try to think that how come this is a graph problem:- I have observed at have assumed that
        //it is basically forming a directed weighted graph.
        
        //Like if our query is like a/e then this eventually means (a/b)*(b/c)*(c/d)*(d/e)
        //Now if we are seeing each query as a directed weighted edge then we can also visualize the upper 
        //query as a ---> b ---> c ---> d ---> e. This can give us some insight's of how we can think this 
        //question as a Graph question and to be more Precise a Directed Weighted Edge Graph is given to 
        //us.
        
        //Since it is a Graph question so first try to think it using BFS/DFS then move to any other Graph 
        //Algorithm for solving this question.

//Now we don't have a Graph like structure here so to visuliaze this as a graph we will have to
        //make a graph here.
        //Can we make an Adjacency List here ?? If not then then what we can use to represent a Graph here
        //Now we can observe that our Hash-Map will work exactly like our Adjacency List

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
            
            if(it.first == dest){ //Now this will also cover the case when source and destination nodes are 
                return it.second; //given same to us from the starting itself then we will simply return 1.
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
                //find value for that query, then in that case we will just push -1 in the array.
                result.push_back(-1);
                continue;
            }
            result.push_back(bfs(o,t));
        }
        return result;
    }
    //Time Complexity:- Since it is BFS so it will be O()
};