#include <stdio.h>
#include<vector>
using namespace std; 

int fun(int (*a)[3]){
	a[1][2] = 3;
} 

int main(){
	int  a[2][3] = {0};	
	fun(a);
	printf("%d", a[1][2]);
	
	return 0;
}

