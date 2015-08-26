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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
   ListNode *p1, *p2
;
   ListNode *re = NULL;
   ListNode *pre = NULL;
   p1 = l1;
   p2 = l2;
   int flag = 0;
   while (true){
    ListNode *p;
    if (p1 != NULL&&p2 != NULL){
     int val = p1->val + p2->val + flag;
     if (val > 9){
      val = val % 10;
      flag = 1;
     }
     else flag = 0;
     p = new ListNode(val);
     p1 = p1->next;
     p2 = p2->next;
    }
    else if (p1 == NULL&&p2 != NULL){
     int val = p2->val + flag;
     if (val > 9){
      val = val % 10;
      flag = 1;
     }
     else flag = 0;
     p = new ListNode(val);
     p2 = p2->next;
    }
    else if (p2 == NULL&&p1 != NULL){
     int val = p1->val + flag;
     if (val > 9){
      val = val % 10;
      flag = 1;
     }
     else flag = 0;
     p = new ListNode(val);
     p1 = p1->next;
    }
    else{
     if (flag == 1){
      p = new ListNode(1);
      pre->next = p;
      break;
     }
     else break;
    }
    if (pre == NULL) {
     re = p;
     pre = re;
    }
    else {
     pre->next = p;
     pre = pre->next;
    }
   }
   return re;
  }
 };