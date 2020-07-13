#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<math.h>

using namespace std;

vector<int> v,ans,tempAns;
int K,P,N,maxFacSum = -1;

void init(){
	int temp = 0;
	for(int i=0; temp<N; i++){
		temp = pow(i,P);
		v.push_back(temp);
	}
}

void dfs(int index, int tempK, int tempSum, int facSum){
	if(tempK == K){
		if(tempSum == N  && facSum > maxFacSum){
			ans = tempAns;
			maxFacSum = facSum;
		}	
		return;
	}
	while(index >= 1){
		if(tempSum + v[index] <= N){
			tempAns[tempK] = index;
			dfs(index, tempK+1, tempSum + v[index], facSum + index);
		}
		if (index == 1) return; // ¼ôÖ¦£¬¼ÓËÙ 
		index--;
	}
}

int main(){
	scanf("%d %d %d",  &N, &K, &P); 
	init();
	tempAns.resize(K);
	dfs(v.size()-1, 0, 0, 0);
	if(maxFacSum == -1){
		printf("Impossible");
		return 0;
	}else{
		printf("%d = ", N);
		for(int i=0; i<K; i++){
			if(i != 0)printf(" + ");
			printf("%d^%d", ans[i], P);
		}
		return 0;
	}
}
