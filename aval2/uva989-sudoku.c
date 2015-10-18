#include <stdio.h>
#define MAX_N 16
#define EMPTY 0

int grid[MAX_N][MAX_N];
int N;
int NN;
void print_s(int grid[MAX_N][MAX_N]){
	int i,j;
	for(i=0; i < NN; i++){
		for(j=0; j<NN; j++)
			printf("%d ",grid[i][j]);
		printf("\n");
	}
	printf("\n");
}

int find_empty_pos(int grid[MAX_N][MAX_N], int *r, int *c){
	for((*r) = 0; (*r) < NN; (*r)++){
		for((*c) = 0; (*c) < NN; (*c)++){
			if(grid[(*r)][(*c)] == EMPTY)
				return 1;
		}
	}

	return 0;
}

int is_good(int grid[MAX_N][MAX_N], int r, int c, int n){
	int row, col;
	for(col=0; col < NN; col++)
		if(grid[r][col] == n)
			return 0;
	
	for(row=0; row < NN; row++)
		if(grid[row][c] == n)
			return 0;

	int box_r_start = r - r%N;
	int box_c_start = c - c%N;
	for(row=0; row < N; row++)
		for(col=0; col < N; col++)
			if(grid[row+box_r_start][col+box_c_start] == n)
				return 0;
	return 1;
}

int solve(int grid[MAX_N][MAX_N]){
	int r,c;

	if(!find_empty_pos(grid, &r, &c))
		return 1;
	
	int i;
	for(i=1; i<=NN; i++){
		if(is_good(grid,r,c,i)){
			grid[r][c] = i;
			
			if(solve(grid))
				return 1;
			grid[r][c] = EMPTY;

		}
	}
	return 0;
}

int main(){
	int i,j;
	int print_line = 0;
	while(scanf("%d", &N) == 1){
		if(print_line) printf("\n");
		NN = N*N;

		for(i=0; i<NN; i++){
			for(j=0; j<NN; j++){
				scanf("%d ", &grid[i][j]);
			}
		}
		
		if(solve(grid)){
			for(i=0; i<NN; i++){
				for(j=0; j<NN; j++){
					if(j == NN-1)
						printf("%d", grid[i][j]);
					else
						printf("%d ", grid[i][j]);
				}
				printf("\n");
			}
		}else{
			printf("NO SOLUTION\n");

		}
		print_line = 1;
	}
	
	return 0;
}
