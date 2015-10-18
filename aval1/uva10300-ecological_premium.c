#include <stdio.h>

int n, f;

unsigned long long sum,a,b,c;
int main(){
	int t,i;
	scanf("%d", &n);
	for(t=0; t<n; t++){
		scanf("%d", &f);
		sum = 0;
		for(i=0;i<f;i++){
			scanf("%llu %llu %llu", &a, &b, &c);
			sum += (a*c);	
		}	
		printf("%llu\n", sum);
	}
	return 0;
}
