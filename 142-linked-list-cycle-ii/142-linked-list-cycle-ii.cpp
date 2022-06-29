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
    ListNode *detectCycle(ListNode *head) {
        //BRUTE FORCE USING HASH TABLE
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        map<ListNode*,int> mp;
        ListNode *temp = head;
        while(temp!=NULL){
            if(mp[temp]==1){
                return temp;
            }
            mp[temp]++; 
            temp=temp->next;
        }
        return NULL;
    }
};