class Solution {
public:
    void recursion(int ind, int target , vector<int>& arr, vector<int>& ans, vector<vector<int>>& ds){
        //Base case
        if(target==0){
            ds.push_back(ans);
            return;
        }
        if(ind == arr.size()){
            return;
        }
        for(int i = ind ; i < arr.size() ; i++){
            if(i>ind and arr[i]==arr[i-1]){
                continue;
            }
            if(arr[i]>target){
                break;
            }
            ans.push_back(arr[i]);
            recursion(i+1,target-arr[i],arr,ans,ds);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        sort(candidates.begin(),candidates.end());
        vector<int> ans;
        vector<vector<int>> ds;
        recursion(0,target,candidates,ans,ds);
        return ds;
    }
};