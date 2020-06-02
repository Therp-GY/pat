#include <stdio.h>
#include<stdlib.h>

#define MaxSize 100
#define Error 0

typedef struct stack{
	int data[MaxSize];
	int top;
}stack;

typedef stack* ptrStack;

//	��ջ
//	ptr��ָ���ջ��ָ��	element����ջ��Ԫ�� 
void Push(ptrStack ptr, int element){
	if(ptr->top == MaxSize -1){
		printf("ջ����");
	}else{
		ptr->data[++(ptr->top)]	= element;
	}
}

//	��ջ
//	ptr�� ָ���ջ��ָ��
int Pop(ptrStack ptr){
	if(ptr->top == -1){
		printf("��ջ��");
		return Error;
	}
	return ptr->data[(ptr->top)--];
}

int main(){
	ptrStack sta = (ptrStack)malloc(sizeof(stack));
	sta->top = -1;
	for(int i=0; i<10; i++){
		Push(sta, i);	
	}
	
	for(int i=0; i<5; i++){
		int j = Pop(sta);
	}
	
	for(int i=10; i<15; i++){
		Push(sta,i);	
	}
	
	for(int i=0; i<10; i++){
		int j = Pop(sta);
		printf("%d\n",j);	
	}
	
	return 0;
}
