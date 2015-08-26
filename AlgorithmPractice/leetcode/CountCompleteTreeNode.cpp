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
  int countNodes(TreeNode* root) {
   if (root == NULL) return 0;
   int d=leftDepth(root);
   int num = (1 << d - 1)-1;
   search(root, 1, d, num);
   return num;
  }
  void search(TreeNode* root, int n, int d,int& num ){
   if (root->right == NULL&&root->left == NULL){
    num++;
    return;
   }
   else if (root->right == NULL&&root->left != NULL){
    search(root->left, n + 1, d, num);
    return;
   }
   if (leftDepth(root->right) == (d - n)){
    num += (1 << (d-n-1));
    search(root->right, n + 1, d, num);
   }
   else{
    search(root->left, n + 1, d, num);
   }
  }
  int leftDepth(TreeNode* root){
   if (root == NULL) return 0;
   int d = 0;
   TreeNode* p=root;
   while (p != NULL){
    d++;
    p = p->left;
   }
   return d;
  }
 };