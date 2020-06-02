#include<cstdio>
#include<algorithm>
#define MAX 100010
using namespace std;
typedef struct node{
	int address;
	int key;
	int next;
	bool flag;
}node;

bool compare(node a, node b){
	if(a.flag == false){
		if(b.flag == false){
			return false;
		}else{
			return false;
		}
	}else{
		if(b.flag == false){
			return true;
		}else{
			return a.key < b.key;
		}
	}
}

//int compare(node a, node b) {
//    return (!a.flag || !b.flag )? a.flag > b.flag : a.key < b.key;
//}

node nodelist[MAX];

int main(){
	int n, head, i, size=0, head_exist=0;
	scanf("%d %d", &n, &head);
	if(n == 0){
		return 0;
	}
	for(i=0; i <n; i++){
		int address, key, next;
		scanf("%d %d %d", &address, &key, &next);
		nodelist[address] = {address, key, next, false};
		if(address == head)
			head_exist = 1;	
	}
	
	//	如果首地址没有链表 
	if(!head_exist){
		printf("0 -1\n", head);
		return 0;
	}
	//	
	 
	for(i=head; i!=-1 ; i=nodelist[i].next){
		nodelist[i].flag = true;
		size ++;
	}
	
	sort(nodelist, nodelist+MAX,compare);
	
	printf("%d %05d\n", size, nodelist[0].address); 
	for(i=0; i<size-1; i++){
		printf("%05d %d %05d\n", nodelist[i].address, nodelist[i].key, nodelist[i+1].address);
	}
	printf("%05d %d -1\n", nodelist[i].address, nodelist[i].key);
	
		
}
