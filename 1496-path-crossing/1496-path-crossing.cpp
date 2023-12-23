class Solution {
public:
    bool isPathCrossing(string s) {
        //Think of Origin like (0,0);
        
        set<pair<int,int>> st;
        st.insert({0,0});
        int x = 0;
        int y = 0;
        for(int i = 0 ; i < s.size() ; i++){
            //Now adjust the Chracters according to the Position on the Map
            if(s[i] == 'N'){
                y++;
            }
            else if(s[i] == 'S'){
                y--;
            }
            else if(s[i] == 'W'){
                x--;
            }
            else if(s[i] == 'E'){
                x++;
            }
            if(st.find({x,y}) != st.end()){
                return true;
            }
            st.insert({x,y});
        }
        return false;
    }
};