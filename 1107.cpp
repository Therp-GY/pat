#include<stdio.h>
#include<vector>
#include<algorithm>
#define maxn 1010
using namespace std;

int n,k,c,cntNum;
int hobb[1010],fa[1010],cnt[1010];
vector<int> isRoot;

int cmp1(int a, int b){
	return a > b;
}

int findFather(int x){
	int a = x;
	while(fa[x] != x){
		x = fa[x];
	}
	while(a != fa[a]){
		int z = a;
		a = fa[a];
		fa[z] = x;
	}
	return a;
}

void Union(int a, int b){
	int fA = findFather(a);
	int fB = findFather(b);
	if(fA != fB)fa[fA] = fB;
}

int main(){
	for(int i=0; i<maxn; i++){
		fa[i] = i;
	}
	scanf("%d",&n);
	isRoot.resize(n+1,0);
	for(int i=1; i<=n; i++){
		scanf("%d", &k);
		for(int j=0; j<k; j++){
			int h;
			scanf("%c", &c);	
			scanf("%d", &h);	
			if(hobb[h] == 0){
				hobb[h] = i;
			}
			Union(i, findFather(hobb[h]));	//	?
		}	
	}
	for(int i=1; i<=n; i++){
		if(i == findFather(i)){
			cntNum++;
		}
		isRoot[findFather(i)]++;
		
	}
	sort(isRoot.begin(), isRoot.end(),cmp1);
	printf("%d\n",cntNum);
	for(int i=0; i < cntNum; i++){
		printf("%d", isRoot[i]);
		if(i != cntNum-1)printf(" ");
	}
	return 0;
}
