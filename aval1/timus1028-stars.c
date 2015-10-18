#include <stdio.h>
#include <string.h>
#define MAX 32005

/* http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/ */
int BITree[MAX];

int getSum(int idx){
	int sum = 0;
	for(;idx>0; idx -= idx & -idx)
		sum += BITree[idx];
	return sum;
}

void update(int idx, int val){
	for(;idx<MAX; idx += idx & -idx)
		BITree[idx] += val;
}

int main(){
	int ans[MAX], N, x, y, i;
	memset(ans,0,sizeof(ans));
	memset(BITree,0,sizeof(BITree));

	scanf("%d", &N);
	for(i=0; i<N; i++){
		/* dont need y, because it is sorted in ascending order */
		scanf("%d %d", &x, &y);
		/* getSum(x+1) is the same as how many stars at positions lesser than (x+1)? */
		++ans[getSum(x+1)];
		update(x+1, 1);
	}
	for(i=0; i<N; i++)
		printf("%d\n", ans[i]);
	return 0;
}
