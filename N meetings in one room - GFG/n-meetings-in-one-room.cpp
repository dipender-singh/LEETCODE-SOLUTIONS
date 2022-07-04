// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    //for comparator function we will have to create a struct also
    struct meeting{
        int start;
        int end;
        int pos;
    };
    
    static bool comp(struct meeting m1, meeting m2){
        //if you have to swap then return false
        //if you don't want to swap then return true
        if(m1.end<m2.end) return true;
        if(m1.end>m2.end) return false;
        if(m1.pos<m2.pos) return true;
        return false;// this is the case when if(m1.pos > m2.pos) and 
                     // both of them have equal end time
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meeting meet[n]; // this array will hold meeting number, start and end time
                                // and will have the same data-type as of our structure
        for(int i = 0 ; i < n ; i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i;
        }
        //Now we have stored all my values in my meet array and now we will sort it with the 
        //help of a custom sort function with the help of comparator function
        sort(meet,meet+n,comp);// now by default this will sort my values in inc. order
        vector<int> ans;
        
        int limit = meet[0].end; // now our first meeting will be that meeting
                                 // which will have the smallest end time
    // now any other meeting that have start time just greator than this lmit
    // than that meeting will take place next and it's end time will be our new limit
        ans.push_back(meet[0].pos);
        for(int i = 1 ; i < n ; i++){
            if(meet[i].start > limit){
                ans.push_back(meet[i].pos);
                limit = meet[i].end;
            }
        }
        return ans.size();
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends