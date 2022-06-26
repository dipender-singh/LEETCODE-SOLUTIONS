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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //BRUTE FORCE
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        unordered_map<ListNode* , int>mp;
        ListNode *temp = NULL;
        while(headA!=NULL){ //O(M)
            mp[headA]++;
            headA=headA->next;
        }
        while(headB!=NULL){ //O(N) FOR THE WORST CASE
            if(mp[headB]==1){
                temp = headB;
                break;
            }
           // mp[headB]++;
            headB=headB->next;
        }
        return temp;
    }
    // TC:- O(M)
};
