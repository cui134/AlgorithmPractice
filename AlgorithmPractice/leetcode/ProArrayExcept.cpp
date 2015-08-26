Solution:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> resultList;
  long total=1;
  int zeroFlag = 0;
  for (int i = 0; i < nums.size(); i++){
   if (nums[i] != 0){
    total *= nums[i];
   }
   else zeroFlag += 1;
   
  }
  for (int i = 0; i < nums.size(); i++){
   if (zeroFlag>1){
    resultList.push_back(0);
   }
   else if (zeroFlag == 1){
    if (nums[i] == 0) resultList.push_back(total);
    else resultList.push_back(0);
   }
   else{
    resultList.push_back((total / nums[i]));
   }
   
  }
  return resultList;
    }
};