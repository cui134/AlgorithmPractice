class Solution {
 public:
  bool isPowerOfTwo(int n) {
   if (n == 0) return false;
   int num = n;
   while (true){
    if (num == 1) break;
    if (num % 2 != 0)
     return false;
    num = num >>1;
   }
   return true;
  }
 };