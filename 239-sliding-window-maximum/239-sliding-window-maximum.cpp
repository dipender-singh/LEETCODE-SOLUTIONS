class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        /*Brute Force
        //My observation for the Max Priority Queue Data Structure is that the Windows is moving forward i.e  
        //the element at the front is getting removed and the element is getting included in the windows from  
        //the back just like the operations pop() and push() and max element will be at the top.
        //By Default C++ makes a Max Priority Queue
        priority_queue<int> pq;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0 ; i <= (n-k) ; i++){
            for(int j = i ; j < i+k ; j++){
                pq.push(nums[j]);
            }
            ans.push_back(pq.top());
            pq={};
        }
        return ans;
    }
    //TC IS O(N*K)
    //SC IS O(N)
    */
        //We have to keep all the useful elements of a window in the queue and useful elements are that which 
        //are greator than all the elements on the righ side of the window.
        deque<int> pq(k);
        vector<int> ans;
        int n = nums.size();
        int slow = 0 , fast = 0;
        for(int i = 0 ; i < k ; i++){
            while(pq.size()!=0 and nums[pq.back()]<=nums[i]){
                pq.pop_back();
            }
            pq.push_back(i);
        }
        ans.push_back(nums[pq.front()]);
        for(int i = k ; i < n ; i++){
            //Now we have to remove all the elements from the deque which are not a part of the window because 
            //to us they are of no use
            while(pq.size()!=0 and pq.front() <= (i-k)){
                pq.pop_front();
            }
            while(pq.size()!=0 and nums[pq.back()]<=nums[i]){
                pq.pop_back();
            }
            pq.push_back(i);
            ans.push_back(nums[pq.front()]);
        }
        return ans;
    }
};