#include <stdio.h>
#define MAX 50

/* Knapack sack 0/1 problem */
int V[MAX], W[MAX], D[MAX];
int m[MAX][1024];
int in_knapsack[MAX];

int max(int a, int b){
	return a < b? b : a;
}

int main(){
	int i,j;
	int t,w,n,d,v;
	int count;
	int print_line;

	print_line = 0;
	while(scanf("%d %d", &t, &w) == 2){
		if(print_line)
			printf("\n");
		scanf("%d", &n);
		for(i=1; i<=n; i++){
			scanf("%d %d", &d, &v);	
			W[i] = 3*w*d; 
			D[i] = d;
			V[i] = v;
		}
		
		for(i=0; i<=t; i++)
			m[0][i] = 0; 
		for(i=1; i<=n; i++){
			for(j=0; j<=t; j++){
				if(W[i] <= j){
					m[i][j] = max(m[i-1][j],  m[i-1][ j - W[i] ] + V[i]);
				}else{
					m[i][j] = m[i-1][j];
				}
			}
		}

		count = 0;
		i = n; j = t;
		while(i > 0){
			if(j >= W[i] && m[i][j] - m[i-1][j - W[i]] == V[i]){
				in_knapsack[i] = 1;
				count++;
				j = j - W[i];		
			} else{
				in_knapsack[i] = 0;
			}
			i--;	
		}
		printf("%d\n%d\n", m[n][t], count);
		for(i=1; i<=n; i++){
			if(in_knapsack[i])
				printf("%d %d\n", D[i], V[i]);
		}
		print_line = 1;
	}
	return 0;
}
