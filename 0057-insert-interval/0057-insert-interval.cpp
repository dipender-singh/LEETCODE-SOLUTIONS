class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<vector<int>> ans;
        int n = intervals.size();
        for(int i = 0 ; i < n ; i++){
            //Now we will identify all the cases
            
            //Case-1: When there will be no scope of overlapping because of like this 
            //           .....................[interval]
            //                                            ......[new interval]
            
            if(intervals[i][1] < newInterval[0]){
                //Now here we will simply add the intervals[i] to the ans vector
                ans.push_back(intervals[i]);
            }
            
            //Case-2: This is something like this
            //                                      ....................[interval]
            //   ................[new interval]      
            
            else if(newInterval[1] < intervals[i][0]){
                ans.push_back(newInterval);
                newInterval = intervals[i];
                
            }
            
            
            //Case-3: When there is a scope of merging the values
            
            //      ............................[interval]
            //  ...................[new interval]
            
            //            .............................[interval]
            //                                .............................[new interval]
            
            //So in these cases we will just update the value of newInterval[0] and newInterval[1]
            else if(intervals[i][1]>=newInterval[0] || intervals[i][0]<=newInterval[1]){
                //So now we will update our values
                newInterval[0] = min(intervals[i][0],newInterval[0]);
                newInterval[1] = max(intervals[i][1],newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};