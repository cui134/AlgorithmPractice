class Solution {
public:
 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  vector<int> maxList;
  if (nums.size() == 0) return maxList;
  for (int i = 0; i < nums.size()-k+1; i++){
   vector<int> numsPart;
   numsPart.assign(nums.begin()+i, nums.begin() +i+ k);
   maxList.push_back(findMax(numsPart));
  }
  return maxList;
 }
 int findMax(vector<int>& numsPart){
  int max = -999999;
  for (int i = 0; i < numsPart.size(); i++){
   if (numsPart[i]>max) max = numsPart[i];
  }
  return max;
 }
};