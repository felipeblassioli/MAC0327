#include<stdio.h>
#include <stdlib.h>     /* qsort */

#define MAX 100005
#define PETYA 0
#define GENA 1

int n;
int acc[2][MAX];
int pos[2][MAX];
int sets[2];
int output_size = 0;

typedef struct {
  int s,t;
} Output;

Output output[MAX];

int compareT (const void * a, const void * b)
{
	Output *x = (Output *)a;
	Output *y = (Output *)b;
	
	if(x->s == y->s){	
		if(x->t == y->t) return 0;
		if(x->t < y->t) return -1;
		if(x->t > y->t) return 1;
	}
	else if(x->s < y->s) return -1;
	else return 1;
}

int main(){	
	int i;
	int t, t0, t1, t2;
	int tmp, fail, a,b, min;
	scanf("%d", &n);
	for(i=0; i<=n; i++){
		acc[0][i] = 0;
		acc[1][i] = 0;
		pos[0][i] = MAX;
		pos[1][i] = MAX;
	}
	for(i=1; i<=n; i++){
		scanf("%d", &tmp);
		tmp = tmp-1;
		acc[tmp][i] = acc[tmp][i-1] + 1;
		acc[!tmp][i] = acc[!tmp][i-1];
		pos[tmp][acc[tmp][i]] = i;
	}

	for(t=n; t>0; t--){
		sets[PETYA] = sets[GENA] = 0;
		t0 = t1 = t2 = 0;
		fail = 0;
		while(t0 <= n){
			if(t1+t>acc[PETYA][n] && t2+t>acc[GENA][n]){
				fail = 1;
				break;
			}
			a = pos[PETYA][t1+t];
			b = pos[GENA][t2+t];
			min = a < b? a : b;
		
			if(a<b)
				sets[PETYA]++;
			else
				sets[GENA]++;	
			t1 = acc[PETYA][min];
			t2 = acc[GENA][min]; 		
	
			if(min == n){
				/* It is valid iff:
				* - scores so far now are not equal
				* - last point was made by the player with higher score
				*/
				if(sets[PETYA] == sets[GENA]) fail = 1;
				else if(a<b && sets[PETYA] < sets[GENA]) fail = 1;
				else if(a>b && sets[PETYA] > sets[GENA]) fail = 1;
				break;
			}
			t0 = min;
		}
		if(!fail){
			output[output_size].s = sets[PETYA] > sets[GENA]? sets[PETYA] : sets[GENA];
			output[output_size].t = t;
			output_size++;
		}
	}
	/* If not sorted fails with:
	* 83
	* 1 1 1 1 1 1 2 2 2 2 2 2 1 1 1 1 1 1 2 2 2 2 2 2 2 1 1 1 1 1 1 1 2 2 2 2 2 2 1 1 1 1 1 1 2 2 2 2 2 2 2 1 1 1 1 1 1 1 2 2 2 2 2 2 1 1 1 1 1 1 2 2 2 2 2 2 1 1 1 1 1 1 1
	*/

	qsort(output, output_size, sizeof(Output), compareT);
	printf("%d\n", output_size);
	for(i=0; i<output_size; i++)
		printf("%d %d\n", output[i].s, output[i].t);
	return 0;
}

