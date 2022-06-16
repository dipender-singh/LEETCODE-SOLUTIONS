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
         /* ios_base::sync_with_stdio(0);
          cin.tie(0);cout.tie(0);
        vector<int> ans=nums;
         //using two poiner and sorting
        sort(nums.begin(),nums.end());
        int l = 0, h = nums.size()-1,n1=0,n2=0;
    vector<int> anss;    
        while(l<h){
            if(ans[l]+ans[h] == target){ // ab yahan pe kya hai meri array sorted hai toh original
                                           // index nahi milenge mujhe yahan pe toh in values ko store
                                           // karke unhe phir dobara original array mein search karein
                n1=ans[l];
                n2=ans[h];
                break;
            }
            if((ans[l]+ans[h]) > target){
                h--;
            }
            else if((ans[l]+ans[h]) < target){
                l++;
            }
        }
        for(int i = 0 ; i < ans.size() ; i++){
            if(ans[i]==n1){
                n1=i;
                anss.push_back(n1);
            }
            else if(ans[i] == n2){
                n2=i;
                anss.push_back(n2);
            }
        }
        return anss;
    }*/
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
        
};