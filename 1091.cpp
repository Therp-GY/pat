#include<stdio.h>
#include<vector> 
#include<stdlib.h>
#include<queue>
using namespace std;

int L[6]={1,0,0,-1,0,0};
int M[6]={0,1,0,0,-1,0};
int N[6]={0,0,1,0,0,-1};
int v[65][1290][130];
int visit[65][1290][130];
int m,n,l,t,all,tempAmount;	//all总数  tempAmount一个连接体的个数 

typedef struct pixel{
	int l,m,n;
}pixel;
queue<pixel> q;

bool judge(int l1, int m1, int n1){
	if(l1<0 || l1>=l || m1<0 || m1>=m || n1<0 || n1>=n)return false;	
	if(visit[l1][m1][n1]==1 || v[l1][m1][n1]==0)return false;
	return true;
} 

void bfs(int l1, int m1, int n1){
	visit[l1][m1][n1] = 1;
	q.push(pixel{l1,m1,n1});
	while(!q.empty()){
		pixel temp = q.front();
		q.pop();
		tempAmount++;
		for(int i=0; i<6; i++){
			if(judge(temp.l+L[i], temp.m+M[i], temp.n+N[i])){
				q.push(pixel{temp.l+L[i], temp.m+M[i], temp.n+N[i]});
				visit[temp.l+L[i]][temp.m+M[i]][temp.n+N[i]] = 1;
			}
		}
	}
}

void search(){
	for(int i=0; i<l; i++){
		for(int j=0; j<m; j++){
			for(int r=0; r<n; r++){
				if(visit[i][j][r] == 0 && v[i][j][r] == 1)bfs(i,j,r);
				if(tempAmount >= t)all+=tempAmount;
				tempAmount = 0;
			}
		}
	}
}


int main(){
	scanf("%d %d %d %d", &m, &n, &l, &t);
	for(int i=0; i<l; i++){
		for(int j=0; j<m; j++){
			for(int r=0; r<n; r++){
				int m;
				scanf("%d", &m);
				v[i][j][r] = m;
			}
		}
	}
	search();
	printf("%d", all);
	
}
