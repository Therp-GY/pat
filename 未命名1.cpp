#include <stdio.h>
#include<stdlib.h>

#define MAXSIZE 1000
int queue[MAXSIZE];
int front = -1;
int reer = -1;
void inQ(int ele){
	if((reer+1)%MAXSIZE == front){
		printf("��������");
	}else{
		reer ++;
		queue[reer] = ele;
	}
}

int outQ(){
	if(front == reer){
		printf("���п�");
		return -11111111;
	}else{
		front++;
		return queue[front];
	}
}

struct node{
	int value;
	struct node* leftNode;
	struct node* rightNode;
}node;

typedef struct node* ptrNode;
 
int main(){
	
	
	return 0;
}

