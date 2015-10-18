#include <stdio.h>
#define FLOOR '.'
#define WALL '#'
#define MAX 38 

char lab[MAX][MAX];
int marked[MAX][MAX];

int N;

int v,m,n;
int x[MAX*MAX], y[MAX*MAX];
int wall = 0;

void enqueue(int i, int j){
	if(!marked[i][j]){
		marked[i][j] = 1;
		x[n] = i; y[n] = j;
		n++;
	}
}

void visit(int i, int j){
	if(lab[i][j] == WALL){
		wall++;
	}else{
		enqueue(i,j);
	}
}

void bfs(int start_i, int start_j){
	int i,j;
	m = n = 0;
	enqueue(start_i,start_j);
	while(m<n){
		i = x[m]; j = y[m]; m++;

		visit(i+1, j);
		visit(i, j+1);
		visit(i-1, j);
		visit(i, j-1);	
	}
}

int main(){
	int i,j, resp;

	scanf("%d", &N);
	getchar();
	for(i=0; i<= N+1; i++){
		for(j=0; j<=N+1; j++){
			lab[i][j] = WALL;
			marked[i][j] = 0;
		}
	}
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			scanf("%c", &lab[i][j]);
		}
		getchar();
	}
	bfs(1,1);
	bfs(N,N);	

	resp = (wall-4) * 9;
	printf("%d\n", resp);
	return 0;
}
