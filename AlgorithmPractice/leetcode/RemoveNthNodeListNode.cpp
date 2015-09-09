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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p;
		p=head;
		int len=0;
		int i=0;
		int k=0;
		while(p!=NULL){
			len++;
			p=p->next;
		}
		k=len-n;
		p=head;
		if(k==0)
			return head->next;
		while(p!=NULL){
			i++;
			if(i==k){
				p->next=p->next->next;
				return head;
			}
			p=p->next;
		}

    }
};