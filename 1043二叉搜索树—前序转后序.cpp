#include<stdio.h>
#include<vector> 
using namespace std;

vector<int> pre,post;
int isMirror;

void getPost(int root, int tail){
	int i, j;
	i = root+1;
	j = tail;
	
	if(root > tail)return;
	if(!isMirror){
		
		while(i<=tail && pre[i]<pre[root]){
			i++; //	左到右遍历，右子树根节点 
		}
		while(j>=root+1 && pre[j]>=	pre[root]){
			j--; // 右到左遍历，左子树尾节点 
		}	
		
	}else{
		while(i<=tail && pre[i]>=pre[root]){
			i++;
		}
		while(j>=root+1 && pre[j]<pre[root]){
			j--;
		}	
	}
	
	if(j!=root)getPost(root+1, j);
	if(i!=tail+1)getPost(i, tail);
	post.push_back(pre[root]);
}
int main(){
	int n;
	scanf("%d", &n);
	pre.resize(n);
	for(int i=0;i<n;i++){
		int node;
		scanf("%d",&node);
		pre[i] = node;
	}
		
	isMirror = 0;	
	getPost(0,n-1);
	if(post.size() == n){
		printf("YES\n");
		printf("%d",post[0]);
		for(int i=1;i<post.size();i++){
			printf(" %d",post[i]);
		}		
		return 0;
	}
	
	post.clear();
	isMirror = 1;	
	getPost(0,n-1);
	if(post.size() == n){
		printf("YES\n");
		printf("%d",post[0]);
		for(int i=1;i<post.size();i++){
			printf(" %d",post[i]);
		}		
		return 0;
	}
	printf("NO\n");
	return 0;
}
