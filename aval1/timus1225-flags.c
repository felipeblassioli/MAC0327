#include <stdio.h>

#define WHITE 0
#define RED 1
#define BLUE 2

int n;
long long m[50][4];
long long count(int i, int prev_color){
	if(i==n) return 1;
	long long r;
	r = m[i][prev_color];
	if(r != -1) return r;
	r = 0;
	if(prev_color != WHITE)
		r += count(i+1,WHITE);
	if(prev_color != RED)
		r += count(i+1, RED);
	if(i < (n-1)){
		if(prev_color == WHITE)
			r += count(i+2, RED);
		else if(prev_color == RED)
			r += count(i+2, WHITE);
	}
	m[i][prev_color] = r;
	return r;
}

int main(){
	int i,j;
	scanf("%d", &n);
	
	for(i=0; i<50; i++)
		for(j=0; j<4; j++)
			m[i][j] = -1;
	printf("%lld\n", count(0,BLUE));
	return 0;
}
