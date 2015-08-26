class Solution {
public:
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
     vector<int> diffWaysToCompute(string input) {
   vector<int> resultList;
   vector<int> num;
   vector<char> operators;
   vector<TreeNode*> t;
   vector<TreeNode*> resultListProc;
   int j = 0, i = 0,nn=0;
   for (i = 0; i < input.size(); i++){
    if (input[i] == '-' || input[i] == '+' || input[i] == '*'){
     TreeNode* tt = new TreeNode(++nn);
     t.push_back(tt);
     num.push_back(atoi(&input.substr(j,i-j)[0]));
     operators.push_back(input[i]);
     j =i+1;
    }
    if (i == input.size() - 1){
     TreeNode* tt = new TreeNode(++nn);
     t.push_back(tt);
     num.push_back(atoi(&input.substr(j, i - j+1)[0]));
    }
   }
   
   cal(num, operators, resultList, t, resultListProc);
   return resultList;
  }
  void cal(vector<int>& num, vector<char>& operators, vector<int>& resultList, vector<TreeNode*> &proc, vector<TreeNode*> &resultListProc){
   if (num.size() == 1){
    resultList.push_back(num[0]);
    return;
   }
   for (int i = 0; i < num.size() - 1; i++){
    vector<int> numcpy(num);
    vector<char> operatorscpy(operators);
    vector<TreeNode*> proccpy(proc);
    char op = operators[(i + i + 1) / 2];
    int val;
    switch (op){
    case '+':
     val = num[i] + num[i + 1];
     break;
    case '-':
     val = num[i] - num[i + 1];
     break;
    case '*':
     val = num[i] * num[i + 1];
     break;
    default:
     break;
    }
    TreeNode* tt = new TreeNode(val);
    tt->left = proccpy[i];
    tt->right = proccpy[i+1];
    proccpy.erase(proccpy.begin() + i);
    proccpy.erase(proccpy.begin() + i);
    proccpy.insert(proccpy.begin() + i, tt);
    numcpy.erase(numcpy.begin() + i);
    numcpy.erase(numcpy.begin() + i);
    numcpy.insert(numcpy.begin() + i, val);
    operatorscpy.erase(operatorscpy.begin() + i);
    if (numcpy.size() == 1){
     if (notIn(proccpy[0], resultListProc) == false){
      resultList.push_back(val);
      resultListProc.push_back(proccpy[0]);
     }
     return;
    }
    else{
     cal(numcpy, operatorscpy, resultList, proccpy, resultListProc);
    }
   
   }
  }
  bool notIn(TreeNode* t, vector<TreeNode*>& treeList){
   for (int i = 0; i < treeList.size(); i++){
    if (t->val == treeList[i]->val){
     if (compareTree(t, treeList[i]) == true) return true;
    }
   }
   return false;
  }
  bool compareTree(TreeNode* t1, TreeNode* t2){
   if ((t1->val == t2->val) && t1->left == NULL&&t2->left == NULL&& t1->right == NULL&&t2->right == NULL) return true;
   if (t1->val != t2->val) return false;
   else if (t1->left == NULL&&t2->left != NULL || t1->right == NULL&&t2->right != NULL || t2->left == NULL&&t1->left != NULL || t2->right == NULL&&t1->right != NULL) return false;
   else{
    return compareTree(t1->left, t2->left) && compareTree(t1->right, t2->right);
   }
  }
};