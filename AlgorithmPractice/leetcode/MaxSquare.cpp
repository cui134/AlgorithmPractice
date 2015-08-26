class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
   int i, j;
   int rowCount = matrix.size();
   if (rowCount == 0) return 0;
   int columnCount = matrix[0].size();
   if (columnCount == 0) return 0;
   int **area;
   int max = 0;
   area = new int *[rowCount+1];
   for (i = 0; i <=rowCount; ++i){
    area[i] = new int[columnCount + 1];
    memset(area[i], 0, sizeof(int)*columnCount);
   }
   
   for (i = 0; i < rowCount; i++){
    for (j = 0; j < columnCount; j++){
     if (matrix[i][j] == '0')
      area[i + 1][j + 1] = 0;
     else{
      int min = 99999;
      if (area[i][j]<min) min = area[i][j];
      if (area[i + 1][j]<min) min = area[i + 1][j];
      if (area[i][j + 1]<min) min = area[i][j + 1];
      area[i + 1][j + 1] = min + 1;
     }
     if (area[i + 1][j + 1]>max){
      max = area[i + 1][j + 1];
     }
    }
   }
   return max*max;
  }
 };