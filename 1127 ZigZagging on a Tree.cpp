#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<queue>
using namespace std;
 
vector<int> in,post,result[35];

//	tree存储二叉树的结构，tree[i][0]对应post[i]的左子树在post上的偏移 ， tree[i][1]对应post[i]的右子树在post上的偏移  ，root二叉树根节点的偏移 
int tree[35][2],root;
struct node{
	int index, depth;
};

void buildTree(int &index, int inRoot, int inTail, int postRoot, int postTail){
	if(inRoot > inTail || postRoot > postTail)return; 
	index = postTail;
	int i;
	for(i=inRoot; in[i]!=post[postTail]; i++){
	}
	buildTree(tree[index][0], inRoot, i-1, postRoot, postRoot+(i-inRoot)-1);
	buildTree(tree[index][1], i+1, inTail, postRoot+(i-inRoot), postTail-1);
}

void bfs(){
	queue<node> q;
	q.push(node{root,0});
	while(!q.empty()){
		node temp = q.front();
		q.pop();
		result[temp.depth].push_back(post[temp.index]);
//		printf("depth:%d index:%d\n", temp.depth, temp.index);
		if(tree[temp.index][0]!=0){
			q.push(node{tree[temp.index][0], temp.depth+1}); 
		}
		if(tree[temp.index][1]!=0){
			q.push(node{tree[temp.index][1], temp.depth+1});
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	in.resize(n+1);
	post.resize(n+1);
	for(int i=1; i<=n; i++){
		int node;
		scanf("%d", &node);
		in[i] = node;
	}
	for(int i=1; i<=n; i++){
		int node;
		scanf("%d", &node);
		post[i] = node;
	}
	buildTree(root, 1, n, 1, n);
	bfs();
	printf("%d", result[0][0]);
	for(int i=1;i<35;i++){
		if(i%2 == 1){
			for(int j=0; j<result[i].size(); j++){
				printf(" %d", result[i][j]);	
			}
		}else{
			for(int j=result[i].size()-1; j>=0; j--){
				printf(" %d", result[i][j]);	
			}
		}
	}
	return 0;
}
