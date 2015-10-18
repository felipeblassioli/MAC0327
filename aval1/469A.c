#include <stdio.h>
#define MAX 105

int n, p, q;
int Z[MAX];

int main(){
	int t;
	int i;
	scanf("%d", &n);
	for(i=0; i<=n; i++)
		Z[i] = 0;

	scanf("%d", &p);
	for(i=0; i<p; i++){
		scanf("%d", &t);	
		Z[t] = 1;
	}
	scanf("%d", &q);
	for(i=0; i<q;i++){
		scanf("%d", &t);	
		Z[t] = 1;	
	}
	int count = 0;
	for(i=0; i<=n; i++)
		if(Z[i])
			count++;
	
	if(count == n)
		printf("I become the guy.\n");
	else
		printf("Oh, my keyboard!\n");
			
	return 0;
}

