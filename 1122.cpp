#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int hamMap[210][210], visit[210];
int n,m,k;
vector<int> path;
int  main(){
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		hamMap[a][b] = hamMap[b][a] = 1;
	}
	scanf("%d", &k);
	for(int i=1; i<=k; i++){
		path.clear();
		fill(visit, visit + 210, 0);
		int num;
		scanf("%d", &num);
		for(int j=1; j<=num; j++){
			int node;
			scanf("%d", &node);
			path.push_back(node);
		}
		if(path.size() != n+1)printf("NO\n");
		else{
			if(path[0] != path[n])printf("NO\n");
			else{
				for(int j=0; j<path.size()-1; j++){
					if(hamMap[path[j]][path[j+1]] != 1){
						printf("NO\n");
						break;	
					}
					if(visit[path[j+1]] != 0){
						printf("NO\n");
						break;	
					}
					visit[path[j+1]] = 1;
					if(j == path.size()-2)printf("YES\n");
				}		
			}
		}
	}
} 
