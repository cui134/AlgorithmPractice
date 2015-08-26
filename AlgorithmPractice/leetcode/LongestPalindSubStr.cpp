class Solution {
  public:
   string longestPalindrome(string s) {
    int len = s.size();
    int id = 0;
    int max = 1;
    //int* palindLen = new int[len];
    //memset(palindLen, 1, sizeof(int)*len);
    for (int i = 0; i < 2*len-1; i++){
     int n = check(s, i);
     if (n>max) {
      id = i;
      max = n;
     }
    }
    string re;
    if (id % 2 == 0){
     id = id / 2;
     max = max / 2;
     re.assign(s.begin() + id - max, s.begin() + id + max+1);
    }
    else{
     id = id / 2+1;
     max = max / 2;
     re.assign(s.begin() + id - max, s.begin() + id + max);
    }
   
    return re;
   }
   int check(string s, int id){
    int len = s.size();	  
    int max = 1;
    if (id % 2 == 0){
     id = id / 2;
     int n = (len>2 * id) ? id : (len - id);
     for (int i = 1; i <= n; i++){
      if (s[id - i] == s[id + i]){
       max+=2;
      }
      else{
       return max;
      }
     }
    }
    else{
     max = 0;
     int id1 = id / 2;
     int id2 = id1 + 1;
     int n = (len-id2>id1) ? id1 : (len - id2);
     for (int i = 0; i <=n; i++){
      if (s[id1 - i] == s[id2 + i]){
       max+=2;
      }
      else{
       return max;
      }
     }
    }	  
    return max;
   }
  };