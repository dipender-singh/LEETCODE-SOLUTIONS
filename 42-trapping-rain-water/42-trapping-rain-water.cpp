class Solution {
public:
    
    int trap(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //Now for a particular building water can be collected by taking into consideration two things:
        //1.) Maximum Building in the Left part of the particular building, let it be x 
        //2.) Maximum Building in the Right part of the particular building, let it be y
        //Now for calculating the Rain-water
        //3.) Now for calculating the water stored it will be collected by using the min(x,y)
        //4.) Now water at top of each building will be calculated using 
        //    water[i]= min( max_ele_on_left_of_i , max_ele_on_right_of_i ) - arr[i]
        //5.) So for every lement of arr we will find the max on left of it and max on right of it and will use 
        //    them to calculate the water at the top of each building
        int n = arr.size();
        int x = arr[0] , y = arr[n-1] , area = 0;
        vector<int>max_left;
        max_left.push_back(x);
        int max_right[n];
        max_right[n-1]=y;
        for(int i = 1 ; i < n ; i++){
            x = max( max_left[i-1] , arr[i] );
            max_left.push_back(x);
        }
        for(int i = n-2 ; i >= 0 ; i--){
            max_right[i] = max(arr[i],max_right[i+1]);
        }
        for(int i = 0 ; i < n ; i++){
            area =area + min(max_left[i],max_right[i])-arr[i];
        }
        return area;
    }
};