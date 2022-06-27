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
        //BRUTE FORCE USING HASHING
        unordered_map<ListNode*, int>mp;
        ListNode* temp = head;
        if(head==NULL || head->next==NULL){
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
    }
};