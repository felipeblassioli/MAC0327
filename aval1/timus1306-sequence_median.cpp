#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 250000/2+3

using namespace std;

int main(){
	int N, i, tmp;
	int numbers[MAX];
	double a;

	scanf("%d", &N);	
	for(i=0; i<=N/2; i++)
		scanf("%d", &numbers[i]);
	
	make_heap(numbers, numbers+N/2+1);
	for(; i<N; i++){
		scanf("%d", &numbers[N/2+1]);
		push_heap(numbers,numbers+N/2+2);
		pop_heap(numbers,numbers+N/2+2);
	}

	a = numbers[0];
	if(N % 2 == 0){
		a *= 0.5;
		pop_heap(numbers,numbers+N/2+1);
		a = a + ( numbers[0] * 0.5 );
	}	
	printf("%.1f\n", a);
	return 0;
}
