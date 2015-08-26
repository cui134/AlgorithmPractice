class Solution {
 public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
   int x1, y1, x2, y2;
   int temp[4];
   int area[3];
   area[1] = abs((A - C))*abs((B - D));
   area[2] = abs((E - G))*abs((F - H));
   if (C < E || G < A || D < F || H < B) return area[1] + area[2];
   temp[0] = A;
   temp[1] = C;
   temp[2] = E;
   temp[3] = G;
   sort(temp,4,0,3);
   x1 = temp[1];
   x2 = temp[2];

   temp[0] = F;
   temp[1] = H;
   temp[2] = B;
   temp[3] = D;
   sort(temp, 4, 0, 3);
   y1 = temp[1];
   y2 = temp[2];
   
   area[0] = abs((x2 - x1))*abs((y2 - y1));
   
   return area[2] + area[1] - area[0];
  }
  void sort(int* tt,int n,int s,int e){
   int tmp = tt[s];
   int i = s;
   int j = e;
   while (i < j){
    for (; j>i; j--){
     if (tt[j] < tmp){
      int temp;
      temp = tt[j];
      tt[j] = tt[i];
      tt[i] = temp;
      break;
     }
    }
    for (; i<j; i++){
     if (tt[i] > tmp){
      int temp;
      temp = tt[j];
      tt[j] = tt[i];
      tt[i] = temp;
      break;
     }
    }
   }
   if(i-s>0) sort(tt, n, s, i);
   if(e-i>1) sort(tt, n, i+1, e);
  }
 };