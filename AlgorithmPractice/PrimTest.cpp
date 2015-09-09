// PrimTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;
int CalEdge(int x,int y,vector<vector<int>> e){
	for(int i=0;i<e.size();i++){
		if((e[i][0]==x||e[i][0]==y)&&(e[i][1]==x||e[i][1]==y)){
			return e[i][2];
		}
	}
	return 999999;
}
void find(vector<int>& vNew,vector<int>& vRemove,vector<vector<int>> e,vector<vector<int>>& eNew){
	int minEdge=99999;
	int minV,minI;
	vector<int> ele;
	for(int i=0;i<vNew.size();i++){
		for(int j=0;j<vRemove.size();j++){
			int edge=CalEdge(vNew[i],vRemove[j],e);
			if(edge<minEdge){
				minEdge=edge;
				minV=j;
				minI=i;
			}
		}
	}
	ele.push_back(vNew[minI]);//insert eNew
	ele.push_back(vRemove[minV]);
	ele.push_back(minEdge);
	for(int i=0;i<vNew.size();i++){//insert vNew
		if(vRemove[minV]>=vNew[i]){
			vNew.insert(vNew.begin()+i+1,vRemove[minV]);
			break;
		}else if(i==vNew.size()-1){
			vNew.insert(vNew.end(),vRemove[minV]);
			break;
		}
	}
	vRemove.erase(vRemove.begin()+minV);//remove vRemove
	eNew.push_back(ele);
}

void Prim(vector<int> v,vector<vector<int>> e,vector<int>& vNew,vector<vector<int>>& eNew){
	vector<int> vRemove(v);
	vRemove.erase(vRemove.begin());
	while(v.size()!=vNew.size()){
		find(vNew,vRemove,e,eNew);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int k=5;
	vector<int> v,vNew;
	vector<vector<int>> e,eNew;
	for(int i=0;i<k;i++){
		v.push_back(i+1);
	}
	vector<int> ele[10];
	ele[0].push_back(1);
	ele[0].push_back(2);
	ele[0].push_back(5);

	ele[1].push_back(1);
	ele[1].push_back(3);
	ele[1].push_back(11);

	ele[2].push_back(1);
	ele[2].push_back(5);
	ele[2].push_back(6);

	ele[3].push_back(2);
	ele[3].push_back(3);
	ele[3].push_back(10);

	ele[4].push_back(3);
	ele[4].push_back(4);
	ele[4].push_back(9);

	ele[5].push_back(3);
	ele[5].push_back(5);
	ele[5].push_back(7);

	ele[6].push_back(4);
	ele[6].push_back(5);
	ele[6].push_back(12);
	for(int i=0;i<7;i++){
		e.push_back(ele[i]);
	}
	vNew.push_back(1);
	Prim(v,e,vNew,eNew);
	return 0;
}

