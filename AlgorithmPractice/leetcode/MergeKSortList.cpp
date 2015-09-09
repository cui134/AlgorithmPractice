/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

vector<ListNode*>* pp;
bool cmp(int a,int b){
 return (*pp)[a]->val<(*pp)[b]->val;
}
class Solution {
public:
 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
  ListNode* re=NULL;
  ListNode* rep;
  int k=lists.size();
  if(k==0)
   return re;
  int pk;
  vector<ListNode*> p;
  vector<int> sortIndex;
  int ii=0;
  for(int i=0;i<k;i++){
   if(lists[i]!=NULL){
   p.push_back(lists[i]);
   sortIndex.push_back(ii);
   //InsertSortIndexList(p,sortIndex,ii);
   ii++;
   }
  }
  k=ii;
  pp=&p;
  sort(sortIndex.begin(),sortIndex.end(),cmp);
  if(p.size()==0)
   return re;
  re=new ListNode(p[sortIndex[0]]->val);
  rep=re;
  p[sortIndex[0]]=p[sortIndex[0]]->next;
  pk=sortIndex[0];
  sortIndex.erase(sortIndex.begin());
  while(true){
   if(p[pk]==NULL&&sortIndex.size()!=0){
    pk=sortIndex[0];
    sortIndex.erase(sortIndex.begin());
   }
   if(sortIndex.size()==0){
    while(p[pk]!=NULL){
    ListNode* t=new ListNode(p[pk]->val);
    p[pk]=p[pk]->next;
    rep->next=t;
    rep=rep->next;
    }
    break;
   }else if(p[pk]->val<=p[sortIndex[0]]->val){
    ListNode* t=new ListNode(p[pk]->val);
    p[pk]=p[pk]->next;
    rep->next=t;
    rep=rep->next;
   }else{
    InsertSortIndexList(p,sortIndex,pk);
    pk=sortIndex[0];
    sortIndex.erase(sortIndex.begin());
    ListNode* t=new ListNode(p[pk]->val);
    p[pk]=p[pk]->next;
    rep->next=t;
    rep=rep->next;
   }
  }
  return re;
 }
 void InsertSortIndexList(vector<ListNode*>& lists,vector<int>& sortIndex,int index){
  if(sortIndex.size()==NULL)
   sortIndex.push_back(index);
  else{
   int len=sortIndex.size();
   if(lists[index]==NULL)
    return;
   for(int i=0;i<len;i++){
    if(lists[index]->val<=lists[sortIndex[i]]->val){
     sortIndex.insert(sortIndex.begin()+i,index);
     return;
    }
   }
   sortIndex.push_back(index);
  }
 }
 
};
