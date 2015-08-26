class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
   int len = nums.size();
   int* startPos = &nums[0];
   vector<int> list;
   unordered_map<int, int> m;
   for (int i = 0; i < len; i++)
    m[nums[i]] = i;
   for (int i = 0; i < len; i++){
    if (m.find((target - nums[i])) != m.end() && m[(target - nums[i])]!=i){
     list.push_back(i + 1);
     list.push_back(m[(target - nums[i])] + 1);
     return list;
    }
   }
   return list;
  }
 };