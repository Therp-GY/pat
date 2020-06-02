#include <stdio.h>
#include<stdlib.h>
typedef struct node{
	int i;
	struct node* next;
}node;
typedef node* ptrToNode;
typedef node* List;


//	���������� 
//	ptr������ͷָ�� 
int length(List ptr){
	List p = ptr;
	int j = 0;
	while(p){
		p = p -> next;
		j++;
	}
	return j;
}

//	���ص�k���ڵ�
//	k����k��λ��  ptr������ͷָ�� 
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

//	�ڵ� position - 1 ���ڵ�����һ��ֵΪX���½ڵ� 
//	��������ͷָ�� 
//	ptr��������ͷָ��  i������  position������λ�� 
List insert(List ptr, int i, int position){
	List s = (ptrToNode)malloc(sizeof(node));
	s->i = i;
	s->next = NULL;
	if(position == 1){
		s->next = ptr;
		return s;
		//	�����µ�ͷָ�� 
	}
	List p  = findKth( ptr,position-1);
	if(p == NULL){
		printf("��������");
		return NULL; 
	}
	s->next = p->next;
	p->next =  s;
	return ptr;
}

//	��������ͷָ�� 
List delet(List ptr, int position){
	if(position == 1){
		List s = ptr;
		ptr = ptr->next;
		free(s);
		return ptr;
	}
	List p = findKth(ptr, position-1);
	if(p == NULL){
		printf("��������");
		return NULL;
	}else if(p->next == NULL){
		printf("��������");
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
	
	printf("\nɾ�����ĸ�����\n");
	printAll(head);
	
	head = delet(head, 1);
	
	printf("\nɾ���ײ�\n");
	printAll(head);
	
	head = insert(head, 100, 1);
	
	printf("\n�ײ�����100\n");
	printAll(head);
	
	printf("\nȫ����\n");
	printf("length is %d",length(head));
	return 0;
}

