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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || left == right) {
            return head;
        }
        
        // Dummy node to handle cases where left == 1
        ListNode dummy(0);
        dummy.next = head;
        
        // Find the node before the left-th node
        ListNode* prevLeft = &dummy;
        for (int i = 0; i < left - 1; i++) {
            prevLeft = prevLeft->next;
        }
        
        // Reverse the sublist
        ListNode* prev = nullptr;
        ListNode* curr = prevLeft->next;
        ListNode* temp = nullptr;
        for (int i = 0; i <= right - left; i++) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        // Connect the reversed part back to the list
        prevLeft->next->next = curr;
        prevLeft->next = prev;
        
        return dummy.next;
    }
};
