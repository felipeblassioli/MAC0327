#include <stdio.h>
#include <math.h>
#define MAX 200008

int k, n;
long long prime[MAX];
/* check codeforces.com/blog/entry/3519 */
/* until 100 000 there are 9592 primes and the last lower prime is 99991 */
/* untill 1 000 000 there are 78489 primes and the last lower prime is 999983 */
void sieve(){
	long long i, j, m, tmp[MAX];

	for(i=0;i<MAX;i++)
		tmp[i] = 1;

	m = sqrt(MAX);
	for(i=2; i<=m; i++){
		if(tmp[i]){
			for(j=i*i; j<MAX; j+=i)
				tmp[j] = 0;
		}	
	} 
	j = 0;
	for(i=2;i<MAX;i++)
		if(tmp[i])
			prime[++j] = i;
}
int main(){
	int i;
	sieve();
	scanf("%d", &k);
	for(i=0; i<k; i++){
		scanf("%d", &n);	
		printf("%lld\n", prime[n]);	
	}	
	return 0;
}
