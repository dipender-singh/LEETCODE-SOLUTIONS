class Solution {
public:
    using lli = long long int;
    
    lli find_max(vector<int>& time){
        int ans = 0;
        for(auto it : time){
            ans = max(ans,it);
        }
        return ans;
    }
    
    lli check(vector<int>& time, lli mid, lli k){
        //If we are able to complete >= k trips in <=mid time, then return 1 else return 0
        lli trips = 0;
        for(auto it : time){
            trips += mid / it;
        }
        return (trips >= k);
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
                
        lli low = 1;
        lli high = find_max(time) * totalTrips;
        lli ans = 0;
        while(low <= high){
            lli mid = low + (high - low)/2;
        if(check(time,mid,totalTrips) == 1){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
            }
        }
        return ans;
    }
};