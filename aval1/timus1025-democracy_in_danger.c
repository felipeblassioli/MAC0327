#include <stdio.h>
#include <stdlib.h>
#define MAX 110

int K;
int grps[MAX];

int cmp(const void *a, const void *b){
	return (*(int *)a) - (*(int *)b);
}

int main(){
	int i, res;

	scanf("%d", &K);
	for(i=0;i<K;i++)
		scanf("%d", &grps[i]);
	qsort(grps, K, sizeof(int), cmp);
	res = 0;
	for(i=0; i<K/2+1; i++)
		res += (grps[i]/2 + 1);
	printf("%d\n", res);
	return 0;
}
