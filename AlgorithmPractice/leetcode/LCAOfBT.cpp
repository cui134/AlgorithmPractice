/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (p == root || q == root) return root;
  vector<TreeNode*> findOrder;
  vector<int> deepOrder;
  vector<TreeNode*> appearOrder;
  int count[2], cc = 0, pos = 0, min = 999999, pcount = 0,qcount=0;
  deepSearch(root, findOrder, deepOrder);
  for (int i = 0; i < findOrder.size(); i++){
   if ((findOrder[i] == p&&pcount == 0) || (findOrder[i] == q&&qcount == 0)){
    count[cc] = i;
    cc++;
    if (findOrder[i] == p) pcount++;
    if (findOrder[i] == q) qcount++;
   }
   if (cc != 0){
    if (deepOrder[i] < min) {
     min = deepOrder[i];
     pos = i;
    }
   }
   if (cc == 2) break;
  }
  return findOrder[pos];
 }
 void deepSearch(TreeNode* r, vector<TreeNode*> &findOrder, vector<int> &deepOrder){
  static int d = 0;
  deepOrder.push_back(d);
  findOrder.push_back(r);
  if (r->left != NULL){
   d++;
   deepSearch(r->left, findOrder, deepOrder);
   d--;
   deepOrder.push_back(d);
   findOrder.push_back(r);
  }
  if (r->right != NULL){
   d++;
   deepSearch(r->right, findOrder, deepOrder);
   d--;
   deepOrder.push_back(d);
   findOrder.push_back(r);
  }
 }
};