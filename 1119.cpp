#include<stdio.h>
#include<vector>
using namespace std;

vector<int> pre;
vector<int> post;
vector<int> in; 
bool uniq = true;

//	给定头和尾，依次将节点push入in中，in即为中序遍历 
void getIn(int root1, int tail1, int root2, int tail2){
	int i1=0,j1=0,i2=0,j2=0;
	if(root1 > tail1)return;
	if(root1 == tail1){
		in.push_back(pre[root1]);
		return;
	}
	i1 = root1+1;
	j2 = tail2-1;
	if(pre[i1]!=post[j2]){
		for(i2=root2;i2<=tail2-1 && pre[i1]!=post[i2];i2++){
		}
		
		for(j1=i1+1; j1<=tail1 && pre[j1]!=post[j2];j1++){
			
		}
		getIn(i1,j1-1,root2,i2);
		in.push_back(pre[root1]);
		getIn(j1,tail1,i2+1,j2);
		return;	
	}else if(pre[i1]==post[j2]){
		getIn(i1,tail1,root2,tail2-1);
		in.push_back(pre[root1]);
		uniq = false;
		return;
	}

}
int main(){
	int n;
	scanf("%d",&n);
	pre.resize(n);
	post.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}	
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	getIn(0,n-1,0,n-1);
	if(uniq){
		printf("Yes\n");	
	}else{
		printf("No\n");	
	}
	printf("%d",in[0]);
	for(int i=1;i<in.size();i++){
		printf(" %d",in[i]);
	}
	printf("\n");
}
