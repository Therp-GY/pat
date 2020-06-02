#include<stdio.h>
#include<stdlib.h>

#define MAX 100010

typedef struct node{
	char letter;
	int next;
	bool flag;
}Node;

Node nodeList[MAX];

void printAll(int a){
	Node nd = nodeList[a];
	while(nd.next != -1){
		printf("letter is %c , flag is %d\n",nd.letter, nd.flag);
		nd = nodeList[nd.next];
	}
	printf("letter is %c , flag is %d\n",nd.letter, nd.flag);
	printf("\n");
}

int main(){
	int h1, h2, n;
	scanf("%d %d %d", &h1, &h2, &n);
	if(!n){
		printf("-1\n");
		return 0;
	}
	while(n){
		char l;
		int start, next;
		scanf("%d %c %d", &start, &l, &next);
		nodeList[start] = {l, next, false};
		n--;
	}
	
//	printAll(h1);
	
	for(int i = h1; i != -1 ;i = nodeList[i].next){
		nodeList[i].flag = true;
	}
	
//	printAll(h1);
	
	for(int i = h2; i != -1 ;i = nodeList[i].next){
		if(nodeList[i].flag == true){
			printf("%05d\n",i);
			return 0;
		}
	}

	printf("-1\n");
	return 0;
	}
