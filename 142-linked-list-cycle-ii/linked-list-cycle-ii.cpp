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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: detect if/where they meet
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break; // met — go to phase 2
        }

        if (fast == nullptr || fast->next == nullptr)
            return nullptr; // no cycle

        // Phase 2: find the start
        ListNode* tmp = head;
        while (tmp != slow) {
            tmp = tmp->next;
            slow = slow->next;
        }
        return tmp;
    }
};