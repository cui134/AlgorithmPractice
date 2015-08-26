class Solution {
  public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merge;
    int idx2 = 0;
    int len1 = nums1.size();
    int len2 = nums2.size();
    int l = (len1 + len2)/2;
    int idx = 0;
    if (len1 == 0 && len2 == 0) return NULL;
    else if (len1 == 0){
     if (len2 % 2 == 0){
      double a = nums2[len2 / 2 - 1];
      double b = nums2[len2 / 2];
      return (a + b) / 2.0;
     }
     else{
      return nums2[len2 / 2];
     }
     
    }
    else if (len2 == 0){
     if (len1 % 2 == 0){
      double a = nums1[len1 / 2 - 1];
      double b = nums1[len1 / 2];
      return (a + b) / 2.0;
     }
     else{
      return nums1[len1 / 2];
     }
    }
    for (int i = 0; i < len1; i++){
     if (idx2 >= len2){
      merge.push_back(nums1[i]);
      idx++;
      continue;
     }
     if (nums1[i] < nums2[idx2]){
      merge.push_back(nums1[i]);
      idx++;
     }
     else{
      merge.push_back(nums2[idx2]);
      idx2++;
      idx++;
      i--;
     }
     if (idx>l){
      if ((len1 + len2) % 2 == 0){
       double a = merge[idx - 2];
       double b = merge[idx-1];
       return (a + b) / 2.0;
      }
      else{
       return merge[idx-1];
      }
     }
    }
    for (int i = idx2; i < len2; i++){
     merge.push_back(nums2[i]);
    }
    int len = merge.size();
    if (len % 2 == 0){
     double a = merge[len / 2 - 1];
     double b = merge[len / 2];
     return (a + b) / 2.0;
    }
    else{
     return merge[len / 2];
    }
   }
  };