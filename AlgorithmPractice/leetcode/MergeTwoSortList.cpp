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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1,*p2,*p3,*head1;		
		p1=l1;
		p2=l2;
		if(l1==NULL)
			return l2;
		else if(l2==NULL)
			return l1;
		if(p1->val<=p2->val){
			ListNode *pp=new ListNode(p1->val);
			p3=pp;
			p1=p1->next;
		}else{
			ListNode *pp=new ListNode(p2->val);
			p3=pp;
			p2=p2->next;
		}
		head1=p3;
		while(p1!=NULL&&p2!=NULL){
			if(p1->val<p2->val){
				ListNode *pp=new ListNode(p1->val);
				p3->next=pp;	
				p1=p1->next;
				p3=p3->next;
			}else{
				ListNode *pp=new ListNode(p2->val);
				p3->next=pp;
				p2=p2->next;
				p3=p3->next;
			}
		}
		if(p1==NULL&&p2!=NULL){
			p3->next=p2;
		}else if(p2==NULL&&p1!=NULL){
			p3->next=p1;
		}
		return head1;
    }
};