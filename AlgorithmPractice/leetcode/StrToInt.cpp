Solution:
 class Solution {
  public:
   int myAtoi(string str) {
    int len = str.size();
    if (len == 0) return NULL;
    long  value = 0;
    bool oper = true;
    int nullCount = 0;
    int id = 0;
    for (int i = 0; i < len; i++){
     if (str[i] == '-'){
      if (str[i + 1] < '0'||str[i + 1] > '9') return 0;
      if (oper) oper = false;
      else oper = true;
      id++;
      break;
     }
     else if (str[i] == '+'){
      if (str[i + 1] < '0'||str[i + 1] > '9') return 0;
      id++;
      break;
     }
     else if (str[i] == ' '){
      nullCount++;
     }
     else if (str[i]>='0'&&str[i]<='9'){
      break;
     }
     else{
      return 0;
     }
     id++;
    }
    if (id > 1 && nullCount==0) return 0;
    if (nullCount == len) return 0;
    int numCount = 0;
    for (int i = id; i < len; i++){
     if (str[i] >= '0'&&str[i] <= '9') numCount++;
     else break;
    }
    if (numCount>10 && oper == true) return INT_MAX;
    else if (numCount>10 && oper == false) return INT_MIN;
    if (oper == false){
     for (int i = id; i <len; i++){
      if (str[i] >= '0'&&str[i] <= '9'){
       value += (str[i] - 48)*pow(10, len - i - 1);
      }
      else {
       value = value / pow(10, len - i);
       break;
      }
     }
     value = 0 - value;
    }
    else if (oper == true){
     for (int i = id; i <len; i++){
      if (str[i] >= '0'&&str[i] <= '9'){
       value += (str[i] - 48)*pow(10, len - i - 1);
      }
      else {
       value = value / pow(10, len - i);
       break;
      }
     }
    }
    if (value>INT_MAX) value = INT_MAX;
    else if (value < INT_MIN) value = INT_MIN;
    return value;
   }
  };