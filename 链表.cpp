#include <stdio.h>
#include<stdlib.h>
typedef struct node{
	int i;
	struct node* next;
}node;
typedef node* ptrToNode;
typedef node* List;


//	返回链表长度 
//	ptr：链表头指针 
int length(List ptr){
	List p = ptr;
	int j = 0;
	while(p){
		p = p -> next;
		j++;
	}
	return j;
}

//	返回第k个节点
//	k：第k个位置  ptr：链表头指针 
List findKth( List ptr,int k){
	List p = ptr;
	int j = 1;
	while(j < k && p != NULL){
		p = p -> next;
		j++;
	}
	if(j != k)return NULL;
	else return p;
}

//	在第 position - 1 个节点后插入一个值为X的新节点 
//	返回链表头指针 
//	ptr：链表传入头指针  i：内容  position：插入位置 
List insert(List ptr, int i, int position){
	List s = (ptrToNode)malloc(sizeof(node));
	s->i = i;
	s->next = NULL;
	if(position == 1){
		s->next = ptr;
		return s;
		//	返回新的头指针 
	}
	List p  = findKth( ptr,position-1);
	if(p == NULL){
		printf("参数错误");
		return NULL; 
	}
	s->next = p->next;
	p->next =  s;
	return ptr;
}

//	返回链表头指针 
List delet(List ptr, int position){
	if(position == 1){
		List s = ptr;
		ptr = ptr->next;
		free(s);
		return ptr;
	}
	List p = findKth(ptr, position-1);
	if(p == NULL){
		printf("参数错误");
		return NULL;
	}else if(p->next == NULL){
		printf("参数错误");
		return NULL;
	}else{
		List s = p->next;
		p->next = s->next;
		free(s);
		return ptr;
	}
}

void printAll(List ptr){
	List p = ptr;
	int j = 0;
	while(p){
		printf("%d \n", p->i);
		p = p -> next;
		j++;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	List head = (List)malloc(sizeof(node));
	head->i = 1;
	head->next = NULL;
	for(int i = 2; i<=n; i++){
		insert(head, i,i);
	}
	printAll(head);
	
	head = delet(head, 4);
	
	printf("\n删除第四个表项\n");
	printAll(head);
	
	head = delet(head, 1);
	
	printf("\n删除首部\n");
	printAll(head);
	
	head = insert(head, 100, 1);
	
	printf("\n首部插入100\n");
	printAll(head);
	
	printf("\n全表长度\n");
	printf("length is %d",length(head));
	return 0;
}

