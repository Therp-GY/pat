#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
using namespace std;
int tree[21][2]={-1}, isRoot[21], root, isLeaf, isCBT, last; // isCBT：是否为完全二叉树   isLeaf：是否开始为叶子节点  

void bfs(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp = q.front();
		last = temp;
		q.pop();
		//	已经开始为叶子节点但却还有子节点 
		if(isLeaf == 1 && (tree[temp][0] != -1 || tree[temp][1] != -1)){
			isCBT = 0;
			return;
		}
		//	左子树无右子树有 
		if(tree[temp][0] == -1 && tree[temp][1] != -1){
			isCBT = 0;
			return;
		}
		if(tree[temp][0] != -1)q.push(tree[temp][0]);
		if(tree[temp][1] != -1)q.push(tree[temp][1]);
		else isLeaf = 1;		
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		string  left, right;
		cin >> left >> right;
		if(left != "-"){
			tree[i][0] = stoi(left);
			isRoot[stoi(left)] = 1;
		}
		if(right != "-"){
			tree[i][1] = stoi(right);
			isRoot[stoi(right)] = 1;
		}
	}
	for(int i=0; i<n; i++){
		if(isRoot[i] == 0){
			root = i;
			break;
		}
	}
	bfs(root);
	if(isCBT){
		printf("YES %d", last);
	}else{
		printf("NO %d", root);
	}
	return 0;
}
