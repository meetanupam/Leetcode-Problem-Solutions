class Solution {
public:
    
    int FindLength(ListNode* head) {
        int l = 0;
        
        while(head) {
            head = head->next;
            l++;
        }
        return l;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {

        
        int Length = FindLength(head);
        
        int k_1 = k;
        ListNode* temp1 = head;
        while(k_1 > 1) {
            temp1 = temp1->next;
            k_1--;
        }
        
        int k_2 = Length-k+1;
        ListNode* temp2 = head;
        while(k_2 > 1) {
            temp2 = temp2->next;
            k_2--;
        }
        
        swap(temp1->val, temp2->val);
        return head;
        
    }
};
