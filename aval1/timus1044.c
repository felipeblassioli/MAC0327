#include <stdio.h>
int n;
int main(){
	int ans[10] = {0,10,670,55252,4816030};
	scanf("%d", &n);
	printf("%d\n", ans[n/2]);
	return 0;
}
