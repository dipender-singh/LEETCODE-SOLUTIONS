class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        //Brute Force is done.  
        //Think about it. 
        vector<int> hbar;
        vector<int> vbar;
        long long ans = -1;
        long long mod = 1e9+7;
        unordered_set<int> st;
        
        hbar.push_back(1);
        hbar.push_back(m);
        vbar.push_back(1);
        vbar.push_back(n);
        
        for(int i = 0 ; i < hFences.size() ; i++){
            hbar.push_back(hFences[i]);
        }
        for(int i = 0 ; i < vFences.size() ; i++){
            vbar.push_back(vFences[i]);
        }
        
        sort(hbar.begin(),hbar.end());
        sort(vbar.begin(),vbar.end());
        
        //Will store all the Distnaces i can get when we keep on removing the Bars in Horizontal Direction or in Vertical Direction. 
        
        //Now we will Bascially take the Boundaries of the Feild and will find the Maximum Gap between any Two Fences
        
        for(int i = 0 ; i < hbar.size() ; i++){
            for(int j = 0 ; j < hbar.size() ; j++){
                st.insert(abs(hbar[i] - hbar[j]));
            }
        }
        
        //Now we will iterate over the vbar Vector and will try to get all the Gaps in between any two Vertical Fences at a time. 
        
        for(int i = 0 ; i < vbar.size() ; i++){
            for(int j = 0 ; j < vbar.size() ; j++){
                int to_find = abs(vbar[i] - vbar[j]);
                if(st.find(to_find) != st.end()){
                    ans = max(ans, static_cast<long long>(to_find) * to_find);
                }
            }
        }
        if(ans == 0){
            return -1;
        }
        return ans%mod;
    }
};