class Solution {
public:
    /*
void recursive(int i, int target,vector<int>& candidates ,vector<int>& ans , vector<vector<int>>& final_ans){
        if(i == candidates.size()-1){
        if(target==0){
            final_ans.push_back(ans);
        }
        return;
        }
        while(candidates[i]<=target){
            ans.push_back(candidates[i]);
            recursive(i,target-candidates[i],candidates,ans,final_ans);
 now we have the answer for the target 6 as 2,2,2 now when we make the recursive call our target becomes zero so now after storing it we return and we are at the index 0 only if 2 is at zero index then we remove the last 2 and then again the same condition of candidates[i]<=target will hold true and we will get stuck in an infinite loop so to get out of that loop we will do recursive call till we get to the last index then we will store our answer and then we will return to previous calls 
  
  
            ans.pop_back();
        }
        recursive(i+1,target,candidates,ans,final_ans); 
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<vector<int>> final_ans;
        vector<int> ans;
        recursive(0,target,candidates,ans,final_ans);
        return final_ans;
    }
*/
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
      if (ind == arr.size()) {
        if (target == 0) {
          ans.push_back(ds);
        }
        return;
      }
      // pick up the element 
      if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, ds);

    }
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
      vector < vector < int >> ans;
      vector < int > ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};