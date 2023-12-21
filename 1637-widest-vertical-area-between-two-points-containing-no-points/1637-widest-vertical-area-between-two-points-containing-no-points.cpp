class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        //Brute Force
        vector<int> ans;
        int diff = 0;
        for(int i = 0 ; i < points.size() ; i++){
           ans.push_back(points[i][0]);
        }
        sort(ans.begin(),ans.end());
        for(int i = 1 ; i < ans.size() ; i++){
            diff = max(diff, ans[i] - ans[i-1]);
        }
        return diff;
    }
};