//hint : https://www.youtube.com/watch?v=yDbkQd9t2ig&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=18
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // using extended moore's voting algo
        // ab yahan pe khud socho AT MAX mere araay mein sirf do hi majority ho skti hain jinka                 // count |n/3| se jada hoga ex :- [1,2] yahn pe n/3 hai 1/3 jo ki less than one hai toh yahan           // pe 2 majority element ho jaynge jinka count |n/3| se jada hoga so our answer for this               // particular test case is [1,2]
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int ele1 = -1;
        int ele2 = -1;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]==ele1){
                count1++;
            }
            else if(nums[i]==ele2){
                count2++;
            }
            else if(count1==0){
                 ele1 = nums[i];
                count1++;
            }
            else if(count2==0){
                 ele2 = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1=count2=0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]==ele1){
                count1++;
            }
            else if(nums[i] == ele2){
                count2++;
            }
        }
        if(count1 > nums.size()/3){
            ans.push_back(ele1);
        }
        if(count2 > nums.size()/3){
            ans.push_back(ele2);
        }
        return ans;
    }
};