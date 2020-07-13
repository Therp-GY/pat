#include<iostream>
#include<stdio.h>
using namespace std;

int n,m,k;
const int maxn = 10010;

int fa[maxn] = {0}, cnt[maxn] = {0};
bool exist[maxn] = {false};
int findFather(int x){
	int a = x;
	while(x != fa[x])
		x = fa[x];
	while(a != fa[a]){
		int z = a;
		a = fa[a];
		fa[z] = x;
	}
} 

int Union(int a, int b){
	int fatherA = findFather(a);
	int fatherB = findFather(b);
	if(fatherA != fatherB)fa[fatherA] = fatherB;
}

int main(){
	scanf("%d", &n);
	for(int i=1; i<=maxn; i++){
		fa[i] = i;
	}
	int id, temp;	
	for(int i=0; i<n; i++){
		scanf("%d %d", &k, &id);
		exist[id] = true;
		for(int j=0; j<k-1; j++){
			scanf("%d", &temp);
			exist[temp] = true;
			Union(id,temp);
		}
	}
	for(int i=1; i<=maxn; i++){
		if(exist[i] == true){
			int root = findFather(i);
			cnt[root]++;
		}
	}
	int numtree = 0, numbird = 0;
	for(int i=1; i<=maxn; i++){
		if(cnt[i] != 0 && exist[i] == true){
			numbird += cnt[i];
			numtree++;
		}
	}	
	printf("%d %d\n", numtree, numbird);
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		int a,b;
		scanf("%d%d", &a, &b);
		printf("%s\n", (findFather(a) == findFather(b))?"Yes":"No");
		
	}
	printf("%d", cnt[maxn]);
	return 0;
}


