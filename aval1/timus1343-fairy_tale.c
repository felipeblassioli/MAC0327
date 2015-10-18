#include <stdio.h>

unsigned long long N, begin, end, p;
int total_digits;

int is_prime(unsigned long long a){
    unsigned long long i;
    
	if(a < 2)
		return 0;
    for(i=2; i*i<a; i++){
        if(a % i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int i;
    scanf("%d", &total_digits);
    if(total_digits == 0){
        printf("000000000002\n");
        return 0;
    }
    scanf("%llu", &N);
    i = 12 - total_digits;
    p = 1;
    while(i--)
        p *= 10;

    for(begin = N*p; begin<(N+1)*p; begin++){
            if(is_prime(begin)){
				printf("%012llu\n", begin);
                break;
            }
    }
    return 0;
}
