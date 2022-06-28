/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //BRUTE FORCE
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        if(head==NULL) {
            return false;
        }
        if(head->next==NULL){
            return true;
        }
        vector<int> ans;
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){
            ans.push_back(temp->val);
            size++;
            temp=temp->next;
        }
        int mid = size/2;
        if(size % 2 == 0){ // When the List is of Even Size
            for(int i = mid-1 , j = mid ; i>=0 , j < size ; i-- , j++){
                if(ans[i]!=ans[j]){
                    return false;
                }
            }
        }
        if(size%2!=0){
            for(int i = mid-1 , j = mid+1 ; i>=0 , j < size ; i-- , j++){
                if(ans[i]!=ans[j]){
                    return false;
                }
            }
        }
        return true;
    }
};