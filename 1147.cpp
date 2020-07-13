#include<stdio.h>
#include<vector>
using namespace std;

int M,N,type,change; //	change小于等于1则表示存在heap，type表示heap类型 
vector<int> level[101],post;

void levelToPost(int m, int index){
	//	左子树根节点存在 
	if(index*2+1 < N){
		if(type != (level[m][index] > level[m][index*2+1])){
			type = (level[m][index] > level[m][index*2+1]);	
			change++;
		}
		levelToPost(m, index*2+1);
	}
	//	右子树根节点存在
	if(index*2+2 < N){
		if(type != (level[m][index] > level[m][index*2+2])){
			type = (level[m][index] > level[m][index*2+2]);	
			change++;
		}
		levelToPost(m, index*2+2);
	}
	post.push_back(level[m][index]);
}

int main(){
	scanf("%d",&M);
	scanf("%d",&N);
	for(int i=0; i<M; i++){
		level[i].resize(N);
		for(int j=0; j<N; j++){
			int node;
			scanf("%d",&node);
			level[i][j] = node;
		}
	}
	for(int i=0; i<M; i++){
		levelToPost(i, 0);
		if(change > 1)printf("Not Heap\n");
		else{
			if(type == 1)printf("Max Heap\n");
			else printf("Min Heap\n");
		} 
		for(int j=0; j<N-1; j++){
			printf("%d ", post[j]);
		}
		printf("%d", post[N-1]);
		if(i < M-1)printf("\n");
		change = 0;
		post.clear();
	}
	return 0;
}

