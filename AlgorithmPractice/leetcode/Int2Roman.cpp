#include "Int2Roman.h"
using namespace std;
string Solution::intToRoman(int num){
	string s="";
	char str[]={'I','X','C','M','V','L','D'};
	int n[4],temp=num;
	memset(n,0,4*sizeof(int));
	int i=0;
	while(temp!=0){
		n[i]=temp%10;
		temp=temp/10;
		i++;
	}
	for(int j=i;j>=0;j--){
		if(j==3){
			tran(s,n[j],'M','A','B');
		}else{
			tran(s,n[j],str[j],str[j+4],str[j+1]);
		}
		
	}
	return s;
}
void Solution::tran(string &s, int num,char c1,char c2,char c3){
	switch(num){
		case 0:
			break;
		case 1:
			s.insert(s.end(),c1);
			break;
		case 2:
			s.insert(s.end(),c1);
			s.insert(s.end(),c1);
			break;
		case 3:
			s.insert(s.end(),c1);
			s.insert(s.end(),c1);
			s.insert(s.end(),c1);
			break;
		case 4:
			s.insert(s.end(),c1);
			s.insert(s.end(),c2);
			break;
		case 5:
			s.insert(s.end(),c2);
			break;
		case 6:
			s.insert(s.end(),c2);
			s.insert(s.end(),c1);
			break;
		case 7:
			s.insert(s.end(),c2);
			s.insert(s.end(),c1);
			s.insert(s.end(),c1);
			break;
		case 8:
			s.insert(s.end(),c2);
			s.insert(s.end(),c1);
			s.insert(s.end(),c1);
			s.insert(s.end(),c1);
			break;
		case 9:
			s.insert(s.end(),c1);
			s.insert(s.end(),c3);
			break;
	}
}