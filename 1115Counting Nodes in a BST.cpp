#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;

typedef struct node{
	int v;
	struct node *leftNode;
	struct node *rightNode;
}node;

typedef node* ptrNode; 

ptrNode build(ptrNode root, int value){
	if(root == NULL){
		root = (ptrNode)malloc(sizeof(node));
		root->v = value;
		root->leftNode = NULL;
		root->rightNode = NULL;
		return root;
	}else{
		if(value > root->v){
			root->rightNode = build(root->rightNode, value);
		}else{
			root->leftNode = build(root->leftNode, value);
		}
		return root;
	}
}

vector<int> nums(1000, 0);
int maxDepth = -1;
void dfs(ptrNode root, int depth){
	if(root == NULL){
		maxDepth = max(depth, maxDepth);
		return;
	}
	nums[depth]++;
	dfs(root->leftNode, depth+1);
	dfs(root->rightNode, depth+1);
}

int main(){
	int n;
	scanf("%d", &n);
	ptrNode head = NULL;
	for(int i=0; i<n; i++){
		int value;
		scanf("%d", &value);
		head = build(head, value);
	}
	dfs(head, 0);
	printf("%d + %d = %d",nums[maxDepth-1], nums[maxDepth-2], nums[maxDepth-1]+nums[maxDepth-2]);	
	return 0;
}

