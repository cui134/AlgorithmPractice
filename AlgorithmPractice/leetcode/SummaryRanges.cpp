class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
   vector<string> re;
   int len = nums.size();
   string tempStr="";
   int tempNum = 0;
   int countTempStr = 0;
   for (int i = 0; i < len; i++){
    if (tempStr == ""){
     char t[10];
     sprintf(t,"%d",nums[i]);
     tempStr = t;
     tempNum = nums[i];
     countTempStr++;
    }
    else if ((nums[i] - tempNum) == 1 && countTempStr==1){
     char t[10];
     sprintf(t,"%d",nums[i]);
     tempStr.append("->");
     tempStr.append(t);
     tempNum = nums[i];
     countTempStr++;
    }
    else if ((nums[i] - tempNum) == 1){
     char t[10];
     sprintf(t,"%d",nums[i]);
     int a=tempStr.find(">");
     tempStr.erase(tempStr.begin() + a+1, tempStr.end());
     tempStr.append(t);
     tempNum = nums[i];
     countTempStr++;
    }
    else{
     re.push_back(tempStr);
     char t[10];
     sprintf(t,"%d",nums[i]);
     tempStr = t;
     tempNum = nums[i];
     countTempStr = 1;
    }
    if (i == len - 1){
     re.push_back(tempStr);
    }
   }
   return re;
  }
};