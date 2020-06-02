#include <stdio.h>
#include<stdlib.h>

#define error -11111111
//	队列节点 
typedef struct node{
	int element;
	struct node* next;	
}node;

typedef node* ptrNode;
//	队列信息 
typedef struct qnode{
	ptrNode front;
	ptrNode reer;
}qnode;

typedef qnode* ptrQnode; 

int deleteQ(ptrQnode ptrq){
	if(ptrq->front == NULL){
		printf("队列为空");
		return error;
	}
	int ele = ptrq->front->element;
	ptrNode front = ptrq->front;
	if(ptrq->front == ptrq->reer){
		ptrq->front = ptrq->reer = NULL;
		return ele;
	}else{
		ptrq->front = ptrq->front->next;
		free(front);
		return ele;
	}
	
}

void inQ(ptrQnode ptrq, int ele){
	if(ptrq->front == NULL){
		ptrNode p = (ptrNode)malloc(sizeof(node));
		p->element = ele;
		p->next = NULL;
		ptrq->front = p;
		ptrq->reer = p;
	}else{
		ptrNode p = (ptrNode)malloc(sizeof(node));
		p->element = ele;
		p->next = NULL;	
		ptrq->reer->next = p;
		ptrq->reer = p;
	}
}

int main(){
	ptrQnode ptrQ = (ptrQnode)malloc(sizeof(qnode));
	ptrQ->front = NULL;
	ptrQ->reer = NULL;
	for(int i = 0; i < 10; i++){
		inQ(ptrQ, i);
	}
	for(int i = 0; i < 5; i++){
		int j = deleteQ(ptrQ);
		printf("%d\n", j);
	}
	for(int i = 10; i < 15; i++){
		inQ(ptrQ, i);
	}
	for(int i = 0; i < 10; i++){
		int j = deleteQ(ptrQ);
		printf("%d\n", j);
	}
	return 0;
}
