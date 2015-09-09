#include "stdafx.h"
#include <vector>
#include <map>
#include <queue>
using namespace std;
int extractMin(vector<int>& s,map<int,int>& m,int* vSet,vector<vector<int>> e,map<int,vector<int>>& path){
	int minV,minD=INT_MAX;
	for(int i=0;i<s.size();i++){
		int u=s[i];
		for(int j=0;j<e.size();j++){
			int v;
			if(e[j][0]==u&&vSet[e[j][1]]==0){
				v=e[j][1];
				if(m[u]+e[j][2]<m[v]){
					m[v]=m[u]+e[j][2];
					vector<int> ele(path[u]);
					path[v]=ele;
					path[v].push_back(v);
				}
				if(m[v]<minD){
					minD=m[v];
					minV=v;
				}
			}else if(e[j][1]==u&&vSet[e[j][0]]==0){
				v=e[j][0];
				if(m[u]+e[j][2]<m[v]){
					m[v]=m[u]+e[j][2];
					vector<int> ele(path[u]);
					path[v]=ele;
					path[v].push_back(v);
				}
				if(m[v]<minD){
					minD=m[v];
					minV=v;
				}
			}
		}
	}
	s.push_back(minV);
	vSet[minV]=1;
	return minV;
}
map<int,int> Dijkstra(vector<int> v,vector<vector<int>> e,int se,map<int,vector<int>>& path){
	vector<int> s;
	int* vSet=new int[v.size()+1];
	memset(vSet,0,sizeof(int)*(v.size()+1));
	map<int,int> m;
	for(int i=0;i<v.size();i++){
		m[v[i]]=INT_MAX;
	}
	s.push_back(se);
	vSet[se]=1;
	m[se]=0;
	vSet[se]=1;
	int ii=0;
	int k=v.size();
	vector<int> ele;
	ele.push_back(se);
	path[se]=ele;
	while(ii<k-1){
		ii++;
		int vv=extractMin(s,m,vSet,e,path);
	}
	return m;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int k=5;
	vector<int> v;
	vector<vector<int>> e;
	map<int,vector<int>> path;
	for(int i=0;i<k;i++){
		v.push_back(i+1);
	}
	vector<int> ele[10];
	ele[0].push_back(1);
	ele[0].push_back(2);
	ele[0].push_back(10);

	ele[1].push_back(2);
	ele[1].push_back(3);
	ele[1].push_back(5);

	ele[2].push_back(3);
	ele[2].push_back(4);
	ele[2].push_back(1);

	ele[3].push_back(4);
	ele[3].push_back(5);
	ele[3].push_back(1);

	ele[4].push_back(5);
	ele[4].push_back(1);
	ele[4].push_back(11);

	ele[5].push_back(3);
	ele[5].push_back(5);
	ele[5].push_back(1);

	for(int i=0;i<6;i++){
		e.push_back(ele[i]);
	}
	Dijkstra(v,e,1,path);
	return 0;
}

