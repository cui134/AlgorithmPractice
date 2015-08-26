#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct Node{
	int val;
	int virus;
	int in;
	vector<Node*> out;
	Node(int v = 0) :val(v){
		virus = 0;
		in = 0;
	}
}Node;
int _tmain(int argc, _TCHAR* argv[])
{
	int N, M, K;//N节点数 M边数 K初始病毒数
	int temp;
	int s, e;
	int virus_num = 0;
	queue<Node*> Q;
	cin >> N >> M >> K;
	//cout << Q.empty() << endl;
	Node* nodeList = new Node[N + 1];
	for (int i = 0; i < N; i++){
		nodeList[i].val = i + 1;
	}
	while (K--){
		cin >> temp;
		nodeList[temp].virus = 1;
		Q.push(&nodeList[temp]);
		virus_num++;
	}
	//cout << Q.empty() << endl;
	while (M--){
		cin >> s >> e;
		nodeList[s].out.push_back(&nodeList[e]);
	}
	while (Q.empty() == 0){
		Node* p = Q.front();
		Q.pop();
		for (int i = 0; i < p->out.size(); i++){
			virus_num++;
			p->out[i]->virus++;
			Q.push(p->out[i]);
		}
	}
	cout << virus_num << endl;
	return 0;
}