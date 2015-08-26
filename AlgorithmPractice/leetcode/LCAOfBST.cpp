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
  bool ff = check(root, p, q);
  if (ff == true){
   if (root->left!=NULL&&check(root->left, p, q) == true){
    return lowestCommonAncestor(root->left, p, q);
   }
   else if (root->right != NULL&&check(root->right, p, q) == true){
    return lowestCommonAncestor(root->right, p, q);
   }
   else{
    return root;
   }
  }
  else{
   return NULL;
  }
 }
 bool check(TreeNode* r, TreeNode* p, TreeNode* q){
  queue<TreeNode*> que;
  que.push(r);
  int count = 0;
  while (!que.empty()){
   TreeNode* pp = que.front();
   if (pp->val == p->val || pp->val == q->val) count++;
   que.pop();
   if (pp->left != NULL) que.push(pp->left);
   if (pp->right != NULL) que.push(pp->right);
  }
  if (count == 2) return true;
  else return false;
 }
};