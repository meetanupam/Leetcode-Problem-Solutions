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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            // Swapping the nodes
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Updating the pointers for the next iteration
            prev = first;
            head = first->next;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};
