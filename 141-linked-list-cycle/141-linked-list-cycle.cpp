/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
     bool hasCycle(ListNode *head) {
         ios_base::sync_with_stdio(0);
         cin.tie(0);cout.tie(0);
        //BRUTE FORCE USING HASHING
        unordered_map<ListNode*, int>mp;
        ListNode* temp = head;
        if(head==NULL || head->next==NULL){ // In case of Linked List we will first check for 
                                            // the validity of Head then for the Next of Head. 
            return false;
        }
        while(temp){
            if(mp[temp]==1){
                return true;
            }
            mp[temp]++;
            temp=temp->next;
        }
        return false;
         //TC: O(N)
         //SC: O(N)
    }
};