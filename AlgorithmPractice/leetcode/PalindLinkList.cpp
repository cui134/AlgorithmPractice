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
    bool isPalindrome(ListNode* head) {
        int len = 0;
  int i, j;
  ListNode* p = head;
  int m[50000];
  while (p!= NULL) {
   m[len] = p->val;
   len++;
   p = p->next;
  }
  i = 0;
  j = len - 1;
  while (i<j){
   if (m[i] != m[j]){
    return false;
   }
   i++;
   j--;
  }
  return true;
    }
};