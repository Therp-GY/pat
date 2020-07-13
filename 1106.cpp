#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<math.h>

using namespace std;

vector<int> map[100001];
int minDepth = 100005, amount;

void dfs(int depth, int index){
	if(map[index].empty()){
		if(depth < minDepth){
			minDepth = depth;	
			amount = 1;	
		}else if(depth == minDepth) amount++;
	}else{
		for(int i=0; i<map[index].size(); i++){
			dfs(depth+1, map[index][i]); 
		}	
	}
}
int main(){
	int n;
	double p,r,price;
	scanf("%d %lf %lf", &n, &p, &r);
	for(int i=0; i<n; i++){
		int k;
		scanf("%d", &k);
		for(int j=0; j<k; j++){
			int t;
			scanf("%d", &t);
			map[i].push_back(t);
		}
	}
	dfs(0, 0);
	price = p * pow(1+0.01*r, minDepth);
	printf("%0.4lf %d",price,amount);
} 
