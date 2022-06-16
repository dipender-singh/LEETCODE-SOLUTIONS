class Solution {
public:
    /*vector<int> twoSum(vector<int>& nums, int target) {
        /*Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        set<int> s;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                if(nums[i]+nums[j]==target){
                   s.insert(i);
                   s.insert(j);
                }
            }
        }
        copy(s.begin(), s.end(), inserter(ans, ans.begin()));
        return ans; */
         /* Using Two Pointer 
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
    	vector<int> res,store;
    	store = nums;

    	sort(store.begin(), store.end());

    	int left=0,right=nums.size()-1;
    	int n1,n2;

    	while(left<right){
        	if(store[left]+store[right]==target){

            	n1 = store[left];
            	n2 = store[right];

            	break;

        	}
        	else if(store[left]+store[right]>target)
            	    right--;
        	else
            	    left++;
    	}

    	for(int i=0;i<nums.size();++i){

        	if(nums[i]==n1)
            	    res.emplace_back(i);
        	else if(nums[i]==n2)
            	    res.emplace_back(i);
    	}

    	    return res;
	}
        */
    // using hashing
     vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        map<int,int> mp;
         vector<int> res;
  for (int i = 0; i < nums.size(); ++i) {

   	 if (mp.find(target - nums[i]) != mp.end()) {

   		 res.emplace_back(i);
   		 res.emplace_back(mp[target - nums[i]]);
   		 return res;
   	 }

   	 mp[nums[i]] = i;
    }

    return res;
     }
};