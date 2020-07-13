#include<stdio.h>
#include<vector>
#include<string>

using namespace std;
vector<int> v[510];
int degree[510],visit[510];
int visitNum;
int n,m;

void dfs(int index){
	visit[index] = 1;
	visitNum++;
	for(int i=0; i<v[index].size(); i++){
		if(visit[v[index][i]] == 0)dfs(v[index][i]);
	}
}
int main(){
	scanf("%d %d",&n, &m);
	for(int i=0; i<m; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		degree[a]++;
		degree[b]++;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	int even=0,odd=0;
	for(int i=1; i<=n; i++){
		printf("%d", degree[i]);
		if(i!=n)printf(" ");
		if(degree[i]%2 == 0)even++;
		else odd++;
	}
	printf("\n");
	if(visitNum != n)printf("Non-Eulerian");
	else if(odd == 0)printf("Eulerian");
	else if(odd == 2)printf("Semi-Eulerian");
	else printf("Non-Eulerian");	
}
