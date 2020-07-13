#include<stdio.h>
#include<vector>
#include<algorithm>
#define inf 999999999
using namespace std;

int n,m,c1,c2;
int lenMap[510][510], dis[510], disPre[510], visit[510], people[510], peoMap[510][510], peo[510], pathNum[510]; //people ´æ´¢ÈËÊý  
vector<int> disPath;

void dfsPath(int index){
	disPath.push_back(index);
	if(index == c1)return;
	dfsPath(disPre[index]);
}
int main(){
	fill(lenMap[0], lenMap[0] + 510*510, inf);
	fill(dis, dis + 510, inf);
	fill(peoMap[0], peoMap[0] + 510*510, 0);
	scanf("%d %d %d %d", &n,&m,&c1,&c2);
	for(int i=0; i<n; i++){
		int p;
		scanf("%d", &p);
		people[i] = p;
	}	
	for(int i=0; i<m; i++){
		int a,b,len;
		scanf("%d %d %d", &a, &b, &len);
		lenMap[a][b] = len;
		lenMap[b][a] = len;
		peoMap[a][b] = people[b];
		peoMap[b][a] = people[a];
	}
	///
	dis[c1] = 0;
	peo[c1] = people[c1];
	pathNum[c1] = 1;
	for(int i=0; i<n; i++)disPre[i] = i;
	for(int i=0; i<n; i++){
		int u = -1, min = inf;
		for(int j=0; j<n; j++){
			if(visit[j] == 0 && dis[j] < min){
				u = j;
				min = dis[j];
			}
		}	
		if(u == -1)break;
		visit[u] = 1;
		for(int v=0; v<n; v++){
			if(visit[v] == 0 && lenMap[u][v] != inf){
				if(dis[u] + lenMap[u][v] < dis[v]){
					dis[v] = dis[u] + lenMap[u][v];
					disPre[v] = u;
					peo[v] = peo[u] + peoMap[u][v];
					pathNum[v] = pathNum[u]; 
				}else if(dis[u] + lenMap[u][v] == dis[v] ){
					pathNum[v] = pathNum[v] + pathNum[u];
					if(peo[u] + peoMap[u][v] > peo[v]){
						disPre[v] = u;
						peo[v] = peo[u] + peoMap[u][v];
					}
				}
			}
		}
		if(u == c2)break;
	}
	dfsPath(c2);
	printf("%d ", pathNum[c2]);
	printf("%d", peo[c2]);

	return 0;
} 
