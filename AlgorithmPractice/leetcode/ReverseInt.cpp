class Solution {
  public:
   int reverse(int x) {
    int num = x;
    int n = 0;
    int *numwei = new int[20];
    int value = 0;
    memset(numwei, 0, sizeof(int)* 20);
    int i = 0;
    while (num!=0){
     numwei[i] = num % 10;
     num /= 10;
     i++;
     n++;
    }
    if (n > 10) return 0;
    if (n == 10){
     for (int j = 0; j < n; j++){
      if (value>(INT_MAX - numwei[j] * pow(10, (n - j - 1))))
       return 0;
      value += numwei[j] * pow(10, (n - j - 1));
     }
    }
    else{
     for (int j = 0; j < n; j++){
      value += numwei[j] * pow(10, (n - j - 1));
     }
    }
   
    return value;
   }
  };