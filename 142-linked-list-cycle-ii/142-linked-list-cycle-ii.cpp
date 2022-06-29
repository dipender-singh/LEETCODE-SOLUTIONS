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
    /*
    ListNode *detectCycle(ListNode *head) {
        //BRUTE FORCE USING HASH TABLE
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        map<ListNode*,int> mp; // SC IS O(N)
        ListNode *temp = head;
        while(temp!=NULL){ // TC is O(N) because if cycle is there then the Last Node will be pointing 
            // to another node so for it we will have to traverse the whole list
            if(mp[temp]==1){
                return temp;
            }
            mp[temp]++; 
            temp=temp->next;
        }
        return NULL;
    }
    */
    //WE WILL BE USING TWO POINTER APPROACH
//HINT OR SOLUTION:- 
//https://www.youtube.com/watch?v=QfbOhn0WZ88&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=38
    ListNode *detectCycle(ListNode *head){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
             if(fast==slow){
                 ListNode *dummy = head;
        while(dummy!=slow){
            dummy=dummy->next;
            slow=slow->next;
        }
                 return dummy;
            }
        }
        return NULL;
    }
};