#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;
vector<int> pre,in;
int isFind;
void firstPost(int preHead, int preTail, int inHead, int inTail){
	if(isFind)return;
	if(preHead > preTail || inHead > inTail)return;
	if(preHead == preTail){
		printf("%d",pre[preHead]);
		isFind = 1;
		return;
	}
	int i;
	for(i=inHead; i<=inTail && in[i]!=pre[preHead]; i++){
	}
	firstPost(preHead+1, preHead+(i-inHead), inHead, i-1);
	firstPost(preHead+(i-inHead)+1, preTail, i+1, inTail);
}
int main(){
	int n;
	scanf("%d",&n);
	pre.resize(n);
	in.resize(n);
	for(int i=0; i<n; i++){
		int node;
		scanf("%d",&node);
		pre[i] = node;
	}	
	for(int i=0; i<n; i++){
		int node;
		scanf("%d",&node);
		in[i] = node;
	}	
	firstPost(0,n-1,0,n-1);
	return 0;
} 
