class Solution {
public:
   ListNode* swapPairs(ListNode* head) {
        int i=0;
		ListNode *p;
		p=head;
		ListNode* pLast=NULL;
		while(p!=NULL&&p->next!=NULL){
			i++;
			if(p->next->next!=NULL){
				ListNode* p1=p->next;
				ListNode* p2=p->next->next;
				p->next=p2;
				p1->next=p;
				if(i==1)
					head=p1;				
				if(pLast!=NULL){
					pLast->next=p1;
				}
				pLast=p;
				p=p->next;
			}else{
				ListNode* p1=p->next;
				p->next=NULL;
				p1->next=p;
				if(i==1)
					head=p1;				
				if(pLast!=NULL){
					pLast->next=p1;
				}
				pLast=p;
				p=p->next;
			}
		}
		return head;
    }
};