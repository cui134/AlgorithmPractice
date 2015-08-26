class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
   vector<int> re;
   if (nums.size() == 0) return re;
   int count1=0;
   int count2 = 0;
   int num1=0;
   int num2=0;
   int num2flag = 0;
   int len = nums.size();
   for (int i = 0; i < len; i++){
    if (nums[i] == num1) count1++;
    else if (nums[i] == num2) {
     num2flag = 1;
     count2++;
    }
    else if (count1 == 0){
     num1 = nums[i];
     count1 = 1;
    }
    else if (count2 == 0){
     num2flag = 1;
     num2 = nums[i];
     count2 = 1;
    }
    else{
     count1--;
     count2--;
    }
   }
   count1 = count2 = 0;
   for (int i = 0; i < len; i++){
    if (nums[i] == num1) count1++;
    if (num2flag == 1&&nums[i] == num2) count2++;
   }
   if (count1>len / 3) re.push_back(num1);
   if (count2>len / 3) re.push_back(num2);
   return re;
  }
};