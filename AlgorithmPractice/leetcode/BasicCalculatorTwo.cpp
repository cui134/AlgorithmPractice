class Solution {
public:
    int calculate(string s) {
   vector<int> numList;
   vector<char> operList;
   int len = s.size();
   int first = 0;
   int result = 0;
   for (int i = 0; i < len; i++){
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
     string numStr;
     string opeStr;
     numStr.assign(s.begin() + first, s.begin() + i);
     int num = atoi(&numStr[0]);
     numList.push_back(num);
     operList.push_back(s[i]);
     first = i + 1;
    }
    if (i == len - 1){
     string numStr;
     numStr.assign(s.begin() + first, s.end());
     int num = atoi(&numStr[0]);
     numList.push_back(num);
    }
   }
   muldiv(numList, operList); //ÏÈËã³Ë³ý£¬ÔÙËã¼Ó¼õ
   result = numList[0];
   for (int i = 0; i < operList.size(); i++){
    switch (operList[i])
    {
    case '+':
     result += numList[i + 1];
     break;
    case '-':
     result -= numList[i + 1];
     break;
    default:
     break;
    }
   }
   return result;
  }
  void muldiv(vector<int> &numList, vector<char> &operList){
   int opeLen = operList.size();
   for (int i = 0; i < opeLen; i++){
    if (operList[i] == '*' || operList[i] == '/'){
     int val;
     switch (operList[i])
     {
     case '*':
      val = numList[i] * numList[i + 1];
      break;
     case '/':
      val = numList[i] / numList[i + 1];
      break;
     default:
      break;
     }
     numList.erase(numList.begin() + i);
     numList.erase(numList.begin() + i);
     numList.insert(numList.begin() + i, val);
     operList.erase(operList.begin() + i);
     muldiv(numList, operList);
     break;
    }
   }
  }
};