#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
int n,m,k,count;
vector<int> v[1005],concern;
int visit[1005];

void bfs(int index, int lost){
	visit[index] = 1;
	for(int i=0; i<v[index].size(); i++){
		if(visit[v[index][i]] == 1 || v[index][i] == lost)continue;
		bfs(v[index][i], lost);
	}
}

void search(int lost){
	count = 0;
	memset(visit,0,sizeof(visit));
	for(int i=1; i<=n; i++){
		if(visit[i] == 1 || i==lost)continue;
		if(visit[i] == 0){
			count++;
			bfs(i, lost);
		}
	}
}

int main(){
	scanf("%d %d %d", &n,&m,&k);
	for(int i=0; i<m; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=0; i<k; i++){
		int c;
		scanf("%d", &c);
		concern.push_back(c);
	}
	for(int i=0; i<concern.size(); i++){
		search(concern[i]);
		printf("%d\n", count-1);
	}
	return 0;
}
