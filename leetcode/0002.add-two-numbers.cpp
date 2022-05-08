 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummpyHead;
        ListNode* p;
        p = &dummpyHead;
        int divide = 0;
        while (l1 || l2) {
            int v1 = 0;
            int v2 = 0;
            if (l1) {
                v1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                v2 = l2->val;
                l2 = l2->next;
            }
            int sum = v1 + v2 + divide;
            divide = sum / 10;
            p->next = new ListNode{sum % 10};
            p = p->next;
        }
        if (divide > 0) {
            p->next = new ListNode{divide};
        }
        return dummpyHead.next;
    }
};
