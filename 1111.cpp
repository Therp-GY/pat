#include<stdio.h>
#include<vector>
#include<algorithm>
#define inf 999999999
using namespace std;

int lenMap[510][510], timeMap[510][510];
int len[510], lenPre[510], visit[510], weight[510], time[510], timePre[510], node[510];
int n,m,st,fin;
vector<int> lenPath, timePath;

void dfsLenPath(int index){
	lenPath.push_back(index);
	if(index == st)return;
	dfsLenPath(lenPre[index]);
}
void dfsTimePath(int index){
	timePath.push_back(index);
	if(index == st)return;
	dfsTimePath(timePre[index]);
}

int main(){
	fill(lenMap[0], lenMap[0] + 510*510, inf);
	fill(timeMap[0], timeMap[0] + 510*510, inf);
	fill(len, len + 510, inf);
	fill(weight, weight + 510, inf);
	fill(time, time + 510, inf);
	fill(node, node + 510, inf);
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int a,b,flag,len,time;
		scanf("%d %d %d %d %d",&a,&b,&flag,&len,&time);
		lenMap[a][b] = len;
		timeMap[a][b] = time;
		if(flag != 1){
			lenMap[b][a] = len;
			timeMap[b][a] = time;	
		}
	}
	scanf("%d %d",&st,&fin);
	////
	len[st] = 0;
	weight[st] = 0;
	for(int i=0; i<n; i++)lenPre[i] = i;
	for(int i=0; i<n; i++){
		int u = -1, min = inf;
		for(int j=0; j<n; j++){
			if(visit[j] == 0 && len[j] < min){
				u = j;
				min = len[j];
			}
		}
		if(u == -1)break;
		visit[u] = 1;
		 
		for(int v=0; v<n; v++){
			//	±éÀúuµÄÁÚ¾Ó 
			if(visit[v] == 0 && lenMap[u][v] != inf){
				if(lenMap[u][v] + len[u] < len[v]){
					len[v] = lenMap[u][v] + len[u];
				 	lenPre[v] = u;
				 	weight[v] = timeMap[u][v] + weight[u];
				}else if(lenMap[u][v] + len[u] == len[v] && timeMap[u][v] + weight[u] < weight[v]){
					lenPre[v] = u;
				 	weight[v] = timeMap[u][v] + weight[u];
				} 
			}
		}
		
	}
	////
	fill(visit, visit + 510, 0);
	time[st] = 0;
	node[st] = 0;
	for(int i=0; i<n; i++)timePre[i] = i;
	for(int i=0; i<n; i++){
		int u = -1, min = inf;
		for(int j=0; j<n; j++){
			if(visit[j] == 0 && time[j] < min){
				u = j;
				min = time[j];
			}
		}
		if(u==-1)break;
		visit[u] = 1;
		for(int v=0; v<n; v++){
			if(visit[v] == 0 && timeMap[u][v] != inf){
				if(time[u] + timeMap[u][v] < time[v]){
					time[v] = time[u] + timeMap[u][v];
					timePre[v] = u;
					node[v] = node[u] + 1;
				}else if(time[u] + timeMap[u][v] == time[v] && node[u] + 1 < node[v]){
					timePre[v] = u;
					node[v] = node[u] + 1;
				}
			}
		}
	}
	dfsLenPath(fin);
	dfsTimePath(fin);
	printf("Distance = %d", len[fin]);
	if(lenPath == timePath){
		printf("; Time = %d: ", time[fin]);
	}else{
		printf(": ");
		for(int i=lenPath.size()-1; i>=0; i--){
			printf("%d",lenPath[i]);
			if(i != 0)printf(" -> ");
		}
		printf("\nTime = %d: ", time[fin]);
	}
	
	for(int i=timePath.size()-1; i>=0; i--){
		printf("%d",timePath[i]);
		if(i != 0)printf(" -> ");
	}
	return 0;
} 
