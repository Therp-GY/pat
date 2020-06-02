#include <stdio.h>
#include<stdlib.h>

#define MAXSIZE 1000
int queue[MAXSIZE];
int front = -1;
int reer = -1;
void inQ(int ele){
	if((reer+1)%MAXSIZE == front){
		printf("队列已满");
	}else{
		(++reer)%MAXSIZE;
		queue[reer] = ele;
	}
}

int outQ(){
	if(front == reer){
		printf("队列空");
		return -11111111;
	}else{
		(++front)%MAXSIZE;
		return queue[front];
	}
}


int main(){
	
	
	return 0;
}

