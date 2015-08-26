#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
class IPString{
public:
 string m_str;
 vector<string> ip_vec;
 IPString(const char* s){
  m_str.assign(s);
 }
 void findPossiableIP(int n,int index,string* str_temp)//n找第n位ip地址(0~3)，index：从字符串的第index位开始找(0~length-1)
 {
  int l = m_str.length();
  if ((l - index)<(4 - n) || (l - index)>3 * (4 - n)){
   return;
  }
  if (n < 3){
   for (int i = 0; i < 3; i++){
    string s;
    s.assign(m_str, index, i + 1);
    if ((l - index-i-1)<(3 - n) || (l - index-i-1)>3 * (3 - n))
     continue;
    /*string s_next;
    s_next.assign(m_str, index + i + 1, 1);
    if (atoi(&s_next[0])<1 || atoi(&s_next[0])>2)
     continue;*/
    if (atoi(&s[0])>255)
     continue;
    if (str_temp->empty()){
     str_temp->append(s);
    }
    else{
     str_temp->append(".");
     str_temp->append(s);
    }
    findPossiableIP(n + 1, index + i + 1, str_temp);
    int ll = str_temp->length();
    if (n == 0){
     str_temp->clear();
    }else{
     str_temp->assign(*str_temp, 0, ll - s.length() - 1);
    }
   
   }
  }
  else{
   for (int i = 0; i < l - index; i++){
    string s;
    s.assign(m_str, index, i + 1);
    if ((l - index - i - 1)<(3 - n) || (l - index - i - 1)>3 * (3 - n))
     continue;
    if (atoi(&s[0])>255)
     continue;
    if (atoi(&s[0])<255 && atoi(&s[0])>0){
     str_temp->append(".");
     str_temp->append(s);
     ip_vec.push_back(*str_temp);
     int ll = str_temp->length();
     str_temp->assign(*str_temp, 0, ll - s.length() - 1);
    }
   }
  }
 }
};
int _tmain(int argc, _TCHAR* argv[])
{
 IPString ip_str("192168111");
 string str_temp;
 int l = ip_str.m_str.length();
 
 clock_t start_time = clock();
 {
  ip_str.findPossiableIP(0, 0, &str_temp);
 }
 clock_t end_time = clock();
 cout << ip_str.m_str << endl;
 cout << "-----------" << endl;
 for (int i = 0; i < ip_str.ip_vec.size(); i++){
  cout << ip_str.ip_vec[i] << endl;
 }
 cout << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;//输出运行时间
 return 0;
}