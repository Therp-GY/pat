#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#define inf 999999999
using namespace std;

int cmax,n,sp,m;

int current[510], disMap[510][510], dis[510], visit[510]; 
vector<int> disPre[510],path,tempPath;
int minNeed = inf,minBack = inf;
void dfs(int index){
 	tempPath.push_back(index);
	if(index == 0){
		int back=0,need=0;
		for(int i=tempPath.size()-1; i>=0; i--){
			if(current[tempPath[i]] >= 0){
				back += current[tempPath[i]];
			}else{
				if(back + current[tempPath[i]] > 0){
					back = back + current[tempPath[i]];
				}else{
					need -= (back + current[tempPath[i]]); 
					back = 0;
				}
			}
		}
		if(need < minNeed){
			minNeed = need;
			minBack = back;
			path = tempPath;
		}else if(need == minNeed && back < minBack){
			minBack = back;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	for(int i=0; i<disPre[index].size(); i++)dfs(disPre[index][i]);
	tempPath.pop_back();
}

int main(){
	fill(disMap[0], disMap[0] + 510*510, inf);
	fill(dis, dis + 510, inf);
	scanf("%d %d %d %d", &cmax, &n, &sp, &m);
	for(int i=1; i<=n; i++){
		int c;
		scanf("%d", &c);
		current[i] = c - cmax/2;	
	}
	for(int i=0; i<m; i++){
		int si,sj,dis;
		scanf("%d %d %d", &si, &sj, &dis);
		disMap[si][sj] = disMap[sj][si] = dis;
	}
	
	dis[0] = 0;
	for(int i=0; i<=n; i++){
		int u = -1, min = inf;
		for(int j=0; j<=n; j++){
			if(visit[j] == 0 && dis[j] < min){
				u = j;
				min = dis[j];
			}
		}
		if(u == -1)break;
		visit[u] = 1;
		for(int v=0; v<=n; v++){
			if(visit[v] == 0 && disMap[u][v] < inf){
				if(dis[u] + disMap[u][v] < dis[v]){
					dis[v] = dis[u] + disMap[u][v];
					disPre[v].clear();
					disPre[v].push_back(u);
				}else if(dis[u] + disMap[u][v] == dis[v]){
					disPre[v].push_back(u);
				}
			}
		}
	}
	dfs(sp);
	printf("%d ", minNeed);
	for(int i=path.size()-1; i>=0; i--){
		printf("%d", path[i]);
		if(i != 0)printf("->");
	}
	printf(" %d",minBack);
	return 0;
}
