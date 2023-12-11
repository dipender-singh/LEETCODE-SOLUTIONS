class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        //Gonna use Hash-Map here 
        map<int,int> mp;
        for(int i = 0 ; i < arr.size() ; i++){
            mp[arr[i]]++;
        }
        int desired_figure = (arr.size()*25)/100;
        for(auto it : mp){
            if(it.second > desired_figure) return it.first;
        }
        return 0;
    }
};