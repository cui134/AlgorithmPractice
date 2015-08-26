class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
   for (int i = 0; i < matrix.size(); i++){
    if (searchRow(matrix[i], target, 0, matrix[i].size()-1)) return true;
   }
   return false;
  }
  bool searchRow(vector<int>& r, int target,int s,int e){
   int mid = (s + e) / 2;
   if (target<r.front() || target>r.back()) return false;
   if (e - s>1){
    if (r[mid]>target) return searchRow(r, target, s, mid);
    else if (r[mid]<target) return searchRow(r, target, mid, e);
    else return true;
   }
   else{
    if (r[e] == target || r[s] == target) return true;
    else return false;
   }
   
  }
};