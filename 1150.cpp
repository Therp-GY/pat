#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#define inf 999999999
#define TSS "TS simple cycle"
#define TS  "TS cycle"
#define NOTTS "Not a TS cycle"
using namespace std;
int tsMap[210][210], visit[210];
int n,m,k,minDis=inf,minIndex;
string flag;
vector<int> path,minPath;
int  main(){
	fill(tsMap[0], tsMap[0] + 210*210, inf);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		int a,b,dis;
		scanf("%d %d %d", &a, &b, &dis);
		tsMap[a][b] = tsMap[b][a] = dis;
	}
	scanf("%d", &k);
	for(int i=1; i<=k; i++){
		path.clear();
		fill(visit, visit + 210, 0);
		flag = TSS;
		int num,dis=0,visitNum=0;
		scanf("%d", &num);
		for(int j=1; j<=num; j++){
			int node;
			scanf("%d", &node);
			path.push_back(node);
		}
		//printf("Path %d: NA (Not a TS cycle)\n",k);	
		if(path[0] != path[n])flag = NOTTS;  // 满足环路 
		for(int j=0; j<path.size()-1; j++){
			if(tsMap[path[j]][path[j+1]] == inf){  //	不满足通路必NOTTS 
				flag = NOTTS;
				dis = inf;
				break;
			}
			if(visit[path[j+1]] != 0){	//	不满足则必不为TSS，可能为TS 
				flag = TS;
			}else{
				visit[path[j+1]] = 1;
				visitNum++;	
			}
			dis += tsMap[path[j]][path[j+1]];
		}
		if(visitNum != n)flag = NOTTS;
		if(flag == TSS || flag == TS){
			if(dis < minDis){
				minIndex = i;
				minDis = dis;
				minPath = path;
			}
		}
		if(dis != inf){
			printf("Path %d: %d (%s)\n",i,dis,flag.c_str());
		}else{
			printf("Path %d: NA (%s)\n",i,flag.c_str());	
		}
	}
	printf("Shortest Dist(%d) = %d", minIndex, minDis);
} 
