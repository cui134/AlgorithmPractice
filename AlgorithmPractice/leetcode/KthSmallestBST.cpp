class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
   vector<TreeNode*> valList;
   stack<TreeNode*> valTemp;
   order(root, valList, valTemp);
   return valList[k-1]->val;
  }
  void order(TreeNode* root, vector<TreeNode*>& valList, stack<TreeNode*>& valTemp){
   valTemp.push(root);
   if (root->left != NULL){
    order(root->left, valList, valTemp);
    valList.push_back(valTemp.top());
    valTemp.pop();
   }
   else{
    valList.push_back(valTemp.top());
    valTemp.pop();
   }
   if (root->right != NULL){
    order(root->right, valList, valTemp);
   }
  }
 };