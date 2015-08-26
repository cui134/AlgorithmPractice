class Solution {
  public:
   int lengthOfLongestSubstring(string s) {
    int loc[256];
    memset(loc, -1, sizeof(int)* 256);
    int idx = -1; //��ʼλ�ã�i-idx�����㳤��
    int len = s.size();
    int max = 0;
    for (int i = 0; i < len; i++){
     if (loc[s[i]] > idx){ //������ֹ�����ʼλ��Ϊ�ϴγ��ֵ�λ��
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