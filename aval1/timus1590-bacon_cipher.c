#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5005

typedef struct {
    char *suff;
    int suff_len;
} Suffix;

Suffix suffix_array[MAX];

int cmp_suffix(const void *a, const void *b){
    return strcmp(((Suffix *)a)->suff, ((Suffix *)b)->suff);
}

int main(){
    char s[MAX];
    int i,len, ans,lcp;
    scanf("%s", s);    
    
    len = strlen(s);
    for(i=0; i<len; i++){
        suffix_array[i].suff = s+i;
        suffix_array[i].suff_len = len-i;
    }
    
    qsort(suffix_array, len, sizeof(Suffix), cmp_suffix); 
    ans = suffix_array[0].suff_len;
    for(i=0; i<len-1; i++){
        for(lcp=0; lcp < suffix_array[i].suff_len && (suffix_array[i].suff[lcp] == suffix_array[i+1].suff[lcp]); lcp++);
        ans += suffix_array[i+1].suff_len - (lcp);
    }
    printf("%d\n", ans);
    return 0;
}
