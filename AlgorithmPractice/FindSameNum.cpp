#include "stdafx.h"
#include <iostream>
#include <map>
#define BUSY 11
using namespace std;
int same(long num){
 map<int, int> numMap;
 int n=0;
 long temp;
 long chushu = 1;
 temp = num;
 while (1){//¼ÆËãÎ»Êý
  if (temp > 0) {
   chushu *= 10;
   n++;
  }
  else break;
  temp /= 10;
 }
 temp = num;
 chushu = chushu / 100;
 while (1){
  int twoNum;
  int f;
  twoNum = temp / chushu;
  f = numMap[twoNum];
  if (numMap[twoNum] == BUSY){
   return 1;
  }
  numMap[twoNum] = BUSY;
  temp %= chushu*10;
  chushu /= 10;
  if (chushu == 0) break;
 }
 return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
 long num;
 int result;
 cin >> num;
 result = same(num);
 return 0;
}