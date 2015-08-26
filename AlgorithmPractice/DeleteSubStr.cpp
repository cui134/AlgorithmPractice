#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int findSubStr(string &str, string &subStr, int n){
 int num = 0;
 while (1){
  int m;
  m = str.find(subStr);
  if (m < 0)
   return num;
  else{
   str.erase(m, n);
   num++;
  }
 }
}
int _tmain(int argc, _TCHAR* argv[])
{
 string str, subStr;
 int n;
 cout << "please input string:" << endl;
 cin >> str;
 cout << "please input sub string:" << endl;
 cin >> subStr;
 n = subStr.size();
 cout << findSubStr(str, subStr, n) << endl;
 return 0;
}