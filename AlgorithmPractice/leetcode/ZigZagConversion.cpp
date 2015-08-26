class Solution {
  public:
   string convert(string s, int numRows) {
    string re;
    if (numRows == 1) return s;
    int num = 0;
    int step = 2 * numRows - 2;
    int len = s.size();
    for (int i = 0; i < numRows; i++){
     int j = 0;
     while (true){
      if (i == 0 || i == numRows - 1){
       int ids = i + j*step;
       if (ids >= len) break;
       re.push_back(s[ids]);
      }
      else{
       int ids = i + (j / 2)*step + (j % 2)*(step - 2 * i);
       if (ids >= len) break;
       re.push_back(s[ids]);
      }
      j++;
     }
    }
    return re;
   }
  };