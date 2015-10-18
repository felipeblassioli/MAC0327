#include <stdio.h>
#define MAX 128

int N;
int max_k;
int finished;

int da[] = {1, 2, 2, 1, -1, -2, -2, -1}; 
int db[] = {-2, -1, 1, 2, 2, 1, -1, -2};

void construct_candidates(int a[], int k, int candidates[], int *ncandidates){
	int seen[MAX];
	int i,j;
	int r,c,row,col;
	int tmp;

	*ncandidates = 0;
	/*printf("construct_candidates for k=%d max_k=%d\n",k, max_k);*/

	for(i=0;i<max_k;i++)
		seen[i] = 0;

	if(k==1){
		candidates[(*ncandidates)++] = 0;
	}else{
		for(i=1;i<k;i++)
			seen[a[i]] = 1;
		tmp = a[k-1];
		/*printf("\tprev=%d\n", tmp);*/
		row = tmp / N; col = tmp % N;
		/*printf("row = %d, col=%d\n", row, col);*/
		for(i=0;i<8;i++){
			r = row + da[i]; c = col + db[i];
			tmp = r * N + c;
			/*printf("\t-> (%d,%d) -> %d\n",r,c,tmp);*/
			if(r >= 0 && r < N && c >= 0 && c < N && seen[tmp] == 0){
				/*printf("\tadd (%d,%d) -> %d\n",r,c,tmp);*/
				candidates[(*ncandidates)++] = tmp;
			}
		}

	}
}

void print_solution(int a[], int k){
	int i;
	char ch;
	int r,c;
	for(i=1; i<=k; i++){
		r = a[i] / N;
		c = a[i] % N;
		ch = 'a'+r;
		/*printf("(%d, %d) -> %d -> %c%d\n",r,c,a[i],ch,(c+1));*/
		printf("%c%d\n",ch,(c+1));
	}
}

void backtrack(int a[], int k){
	int c[MAX];
	int ncandidates;
	int i;

	if(k == max_k){
		print_solution(a,k);
		finished = 1;
	}else{
		k = k+1;
		construct_candidates(a,k,c,&ncandidates);
		/*printf("a[] = [");*/
		/*for(i=1;i<k;i++)*/
			/*printf("%d ",a[i]);*/
		/*printf("]\n");*/
		/*printf("total candidates=%d\n", ncandidates);*/
		for(i=0; i<ncandidates; i++){
			a[k] = c[i];
			backtrack(a,k);
			if(finished)
				return;
		}
	}
}

int main(){
	int a[MAX];
	int i;
	
	scanf("%d", &N);
	max_k = N*N;

	finished = 0;
	backtrack(a,0);
	if(!finished)
		printf("IMPOSSIBLE\n");
	return 0;
}
