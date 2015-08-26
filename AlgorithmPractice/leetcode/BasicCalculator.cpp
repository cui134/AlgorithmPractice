class Solution {
 public:
  int calculate(string s) {
   cal(s);
   int re;
   re = calculateNoKuohao(s);
   return re;
  }
  void cal(string &str){
   int len = str.size();
   int leftPos = -1;
   for (int i = 0; i < len; i++){
    if (str[i] == '(') leftPos = i;
    if (str[i] == ')'){
     string temp;
     char t[10];
     temp.assign(str.begin() + leftPos + 1, str.begin() + i);
     int val = calculateNoKuohao(temp);
     sprintf(t, "%d", val);
     char oper = str[leftPos - 1];
     
     str.erase(str.begin() + leftPos, str.begin() + i + 1);

     if (val < 0 && oper == '+') {
      str.erase(str.begin() + leftPos - 1, str.begin() + leftPos);
      leftPos -= 1;
     }
     else if (val < 0 && oper == '-'){
      str.erase(str.begin() + leftPos - 1, str.begin() + leftPos);
      t[0] = '+';
      leftPos -= 1;
     }
     for (int j = 0; j < 10; j++){
      if (t[j] != 0){
       str.insert(str.begin() + leftPos + j, t[j]);
      }
      else break;
     }
     cal(str);
     break;
    }
   }
  }
  int calculateNoKuohao(string s){
   int len = s.size();
   int first=0;
   int sum=0;
   char last;
   for (int i = 0; i < len; i++){
    if (s[i] == '+' || s[i] == '-'){
     string temp;
     temp.assign(s.begin() + first, s.begin() + i);
     int val = atoi(temp.c_str());
     if (first == 0) sum = val;
     else{
      switch (last)
      {
      case '+':
       sum += val;
       break;
      case '-':
       sum -= val;
       break;
      default:
       break;
      }
     }
     first = i + 1;
     last = s[i];
    }
    if (i == len - 1){
     string temp;
     temp.assign(s.begin() + first, s.end());
     int val = atoi(temp.c_str());
     if (first == 0) return val;
     switch (last)
     {
     case '+':
      sum += val;
      break;
     case '-':
      sum -= val;
      break;
     default:
      break;
     }
    }
   }
   return sum;
  }
   
 };