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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
   invert(root);
   return root;
  }
  void invert(TreeNode* root){
   if (root->left != NULL || root->right != NULL){
    TreeNode* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    if (root->left != NULL){
     invert(root->left);
    }
    if (root->right != NULL){
     invert(root->right);
    }
   }
  }
};