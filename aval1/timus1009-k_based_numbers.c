#include <stdio.h>
#define MAX 20

int N,K;
long long m[MAX][2];

long long count(int i, int prev_was_zero){
	int j;
	long long r;
	if(i==N)
		return 1;
	if(m[i][prev_was_zero] != -1)
		return m[i][prev_was_zero];
	r = 0;
	if(!prev_was_zero)
		r += count(i+1, 1);
	for(j=1;j<K;j++)
		r += count(i+1,0);
	m[i][prev_was_zero] = r;
	return r;
}

int main(){
	int i;
	scanf("%d", &N);
	scanf("%d", &K);
	for(i=0; i<N; i++){
		m[i][0] = -1;
		m[i][1] = -1;
	}
	printf("%lld\n", count(0,1));
	return 0;
}
