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
    void deleteNode(ListNode* node) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //We will take the adress of the node next to the given node
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = node->next->next;
        delete temp;
    }
};