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
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* p=head;
		ListNode *pNext,*pPre;
		pPre=NULL;
		int i=0;
		while(p!=NULL){
			ListNode *p1;
			int j=0;
			p1=p;
			while(p1!=NULL&&j<k){
				pNext=p1->next;
				p1=p1->next;
				j++;
			}
			if(j==k)
				Reverse(&head,p,pPre,pNext,k);	
			pPre=p;
			p=p->next;
			i++;
		}
		
		
        return head;
    }
	void Reverse(ListNode** listHead,ListNode* head,ListNode* pre,ListNode* next,int k){
		int i=0;
		ListNode *p=head;
		ListNode *pLast=next;
		while(i<k&&p!=NULL){
			ListNode* p1;
			p1=p->next;
			p->next=pLast;
			pLast=p;
			p=p1;
			i++;
		}
		if(pre!=NULL)
			pre->next=pLast;
		else
			*listHead=pLast;
	}
};