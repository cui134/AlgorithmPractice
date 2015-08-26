#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
typedef unsigned char u8;
typedef struct Point{
 int x = 0;
 int y = 0;
};
class SudoMatric{
public:
 u8 sudo_data[10][10];//没有数字，表示为0
 void findPosiableValue(u8 i, u8 j, vector<u8>* v);
 void showSudo();
 void captureData();
 bool huishuoSearch(vector<Point*>* point_buff);
 void writeNumber(vector<u8>* v);
 bool isNullValue();
};

bool SudoMatric::huishuoSearch(vector<Point*>* point_buff)//回朔法给数独填数
{
 vector<u8> v;
 //vector<Point*> point_buff;
 //char error=0;
 bool flag = 1;
 while (isNullValue() != 0 && flag == 1){//先把所有唯一值填完
  flag = 0;
  for (int i = 1; i < 10; i++){
   for (int j = 1; j < 10; j++){
    if (sudo_data[i][j] == 0){//找出该点可能值，如果唯一，则先赋值
     findPosiableValue(i, j, &v);
     if (v.size() == 0) {
      v.clear();
      return 1;
     
     }
     else if (v.size() == 1){
      flag = 1;
      sudo_data[i][j] = v.front();
      Point* pt=new Point;
      pt->x = i;
      pt->y = j;
      point_buff->push_back(pt);
      v.clear();
     }
     else{
      v.clear();
     }
    }
   }
  }
 }
 //cout << "##########################" << endl;
 //showSudo();
 if (isNullValue() != 0){
  for (int i = 1; i < 10; i++){
   for (int j = 1; j < 10; j++){
    if (sudo_data[i][j] == 0){//找出该点可能值
     findPosiableValue(i, j, &v);
     if (v.size() == 0) {
      return 1;
     }

     for (int k = 0; k < v.size(); k++){
      sudo_data[i][j] = v[k];
      bool f = huishuoSearch(point_buff);
      if (f != 0){//搜索失败
       for (int m = 0; m < point_buff->size(); m++){
        Point* p = (*point_buff)[m];
        sudo_data[p->x][p->y] = 0;
        delete p;
       }
       sudo_data[i][j] = 0;
       point_buff->clear();
      }
      else{//搜索成功
       return 0;
      }
     }
     v.clear();
     return 1;//k次搜索都失败，返回1
    }
   }
  }
 }
 else{
  return 0;
 }
 
}
bool SudoMatric::isNullValue()//检测是否全部填完
{
 for (int i = 1; i < 10; i++){
  for (int j = 1; j < 10; j++){
   if (sudo_data[i][j] == 0)
    return 1;
  }
 }
 return 0;
}
void SudoMatric::writeNumber(vector<u8>* v)//写到一半，发现写错了，应该整个函数递归
{
 bool error = false;
 bool flag = 1;
 while (isNullValue() != 0 && flag == 1){//先把所有唯一值填完
  flag = 0;
  for (int i = 1; i < 10; i++){
   for (int j = 1; j < 10; j++){
    if (sudo_data[i][j] == 0){//找出该点可能值，如果唯一，则先赋值
     findPosiableValue(i, j, v);
     if (v->size() == 0) {
      error = true;
      v->clear();
     }
     else if (v->size() == 1){
      flag = 1;
      sudo_data[i][j] = v->front();
      v->clear();
     }
     else{
      v->clear();
     }
    }
   }
  }
 }
 //对所有非唯一值进行回朔填写
 if (isNullValue() != 0){
 
 }
 
}
void SudoMatric::showSudo()//显示
{
 char buff[5];
 for (int i = 1; i < 10; i++){
  for (int j = 1; j < 10; j++){
   _itoa_s(sudo_data[i][j], buff, 10);
    cout << buff << ' ';
   if (j == 3 || j == 6) cout << "| ";
  }
  cout << endl;
  if (i == 3 || i == 6) cout << "---------------------" << endl;
 }
}
void SudoMatric::captureData()//捕获数据，可以手动输入，也可以初始化赋值
{
 //手动输入采集
 /*for (int i = 1; i < 10; i++){
  for (int j = 1; j < 10; j++){
   cin >> sudo_data[i][j];
  }
 }*/
 //固定数组
 //可以通过找唯一值填完
 /*u8 data[9][9] = { { 0, 6, 0, 5, 9, 3, 0, 0, 0 },
 { 9, 0, 1, 0, 0, 0, 5, 0, 0 },
 { 0, 3, 0, 4, 0, 0, 0, 9, 0 },
 { 1, 0, 8, 0, 2, 0, 0, 0, 4 },
 { 4, 0, 0, 3, 0, 9, 0, 0, 1 },
 { 2, 0, 0, 0, 1, 0, 6, 0, 9 },
 { 0, 8, 0, 0, 0, 6, 0, 2, 0 },
 { 0, 0, 4, 0, 0, 0, 8, 0, 7 },
 { 0, 0, 0, 7, 8, 5, 0, 1, 0 }
 };*/
 u8 data[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 1, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 1, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 1 },
       { 0, 0, 0, 0, 1, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 1, 0 }
     };
 for (int i = 1; i < 10; i++){
  for (int j = 1; j < 10; j++){
   sudo_data[i][j] = data[i-1][j-1];
  }
 }
}
void SudoMatric::findPosiableValue(u8 i, u8 j,vector<u8>* v)//找出i，j单元格的可能值，1表示可能，0表示不可能
{
 u8 result = 0;
 u8 num_p[10];
 u8 conflict[10];
 if (i<1 || i>9 || j<1 || j>9) return;
 if (sudo_data[i][j] != 0){
  v->push_back(sudo_data[i][j]);
  return;
 }
 memset(num_p, 1, 10);//9个数都有可能
 memset(conflict, 1, 10);
 for (int m= 1; m < 10; m++){//行 搜索
  if (sudo_data[i][m] != 0 && num_p[sudo_data[i][m]]!=0){
   num_p[sudo_data[i][m]] = 0;
  }
  if (sudo_data[i][m] != 0){
   if (conflict[sudo_data[i][m]] == 0){
    v->clear();
    return;
   }
   else{
    conflict[sudo_data[i][m]] = 0;
   }
  }
  /*else if (sudo_data[i][m] != 0 && num_p[sudo_data[i][m]] == 0){
   v->clear();
   return;
  }*/
 }
 memset(conflict, 1, 10);
 for (int m = 1; m < 10; m++){//列 搜索
  if (sudo_data[m][j] != 0 && num_p[sudo_data[m][j]]!=0){
   num_p[sudo_data[m][j]] = 0;
  }
  if (sudo_data[m][j] != 0){
   if (conflict[sudo_data[m][j]] == 0){
    v->clear();
    return;
   }
   else{
    conflict[sudo_data[m][j]] = 0;
   }
  }
  /*else if (sudo_data[m][j] != 0 && num_p[sudo_data[m][j]] == 0){
   v->clear();
   return;
  }*/
 }
 int x = ((i - 1) / 3) * 3 + 1;
 int y = ((j - 1) / 3) * 3 + 1;
 memset(conflict, 1, 10);
 for (int m = 0; m < 3; m++){//3*3 搜索
  for (int n = 0; n < 3; n++){
   if (sudo_data[x + m][y + n] != 0 && num_p[sudo_data[x + m][y + n]] != 0)
    num_p[sudo_data[x + m][y + n]] = 0;
   if (sudo_data[x + m][y + n] != 0){
    if (conflict[sudo_data[x + m][y + n]] == 0){
     v->clear();
     return;
    }
    else{
     conflict[sudo_data[x + m][y + n]] = 0;
    }
   }
   /*else if (sudo_data[x + m][y + n] != 0 && num_p[sudo_data[x + m][y + n]] == 0){
    v->clear();
    return;
   }*/
  }
 }
 for (int m = 1; m < 10; m++){
  if (num_p[m] == 1){
   v->push_back(m);
  }
 }

}
int _tmain(int argc, _TCHAR* argv[])
{
 SudoMatric sudo;
 vector<Point*> pv;
 vector<u8>* vec=new vector<u8>;
 bool r;
 sudo.captureData();
 sudo.showSudo();
 
 
 clock_t start_time = clock();
 {
  r = sudo.huishuoSearch(&pv);//r非0表示无解
 }
 clock_t end_time = clock();

 cout << "##########################" << endl;
 sudo.showSudo();

 cout << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;//输出运行时间
 
 

 return r;
}