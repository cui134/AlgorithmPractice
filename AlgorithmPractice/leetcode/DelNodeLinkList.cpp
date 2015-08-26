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
        int val = node->val;
  int i = 0;
  ListNode *p = node;
  p = p->next;
  node->val = p->val;
  node->next = p->next;
    }
};