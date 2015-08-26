class Solution {
  public:
   int lengthOfLongestSubstring(string s) {
    int loc[256];
    memset(loc, -1, sizeof(int)* 256);
    int idx = -1; //起始位置，i-idx来计算长度
    int len = s.size();
    int max = 0;
    for (int i = 0; i < len; i++){
     if (loc[s[i]] > idx){ //如果出现过，起始位置为上次出现的位置
      idx = loc[s[i]];
     }
     if (i - idx > max){
      max = i - idx;
     }
     loc[s[i]] = i;
    }
    return max;
   }
  };