#include <stdio.h>
#define MAX 100005

int n,m;
int ex[MAX];
int ey[MAX];
int indexes[MAX];
int allowed[MAX];
int p[MAX];
int sz[MAX];
int ans[MAX];
int q;
int count;

int find(int u){
	int i;
	for(i=u; i != p[i]; i = p[i])
		p[i] = p[p[i]];
	return i;
}

void disj_union(int u, int v){
	int i = find(u);
	int j = find(v);
	int k;

	if(i != j){
		count--;
		if(sz[i] < sz[j])
			p[i] = j;
		else if(sz[j] > sz[i])
			p[j] = i;
		else{
			p[i] = j;
			sz[j]++;
		}
	}
}

int main(){
	int i,j;
	scanf("%d %d", &n, &m);
	count = n;
	for(i=1; i<=m; i++){
		scanf("%d %d", &ex[i], &ey[i]);
		allowed[i] = 1;
	}
	scanf("%d", &q);
	for(i=0; i<q;i++){
		scanf("%d", &indexes[i]);
		allowed[indexes[i]] = 0;
	}
	for(i=1; i<=n; i++){
		p[i] = i;
		sz[i] = 0;
	}
	for(i=1;i<=m;i++){
		if(allowed[i])
			disj_union(ex[i], ey[i]);
	}

	j=1;
	ans[0] = count;
	for(i=q-1; i > 0; i--){
		disj_union(ex[indexes[i]], ey[indexes[i]]);
		ans[j++] = count;
	}

	for(i=q-1; i>0; i--)
		printf("%d ", ans[i]);
	printf("%d\n", ans[i]);
	return 0;
}
