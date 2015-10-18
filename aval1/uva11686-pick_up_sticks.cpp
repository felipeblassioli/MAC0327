#include <cstdio>
#include <vector>

#define MAX 1000002
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

int n,m;
vector<int> adj[MAX];
int color[MAX];
int answer[MAX];
int answer_size;

int fail;
void dfs_visit(int i){
	int j,k;
	color[i] = GRAY;

	for(k=0; k<adj[i].size(); k++){
		j = adj[i][k];
		if(color[j] == WHITE){
			dfs_visit(j);
		}else if(color[j] == GRAY){
			fail = 1;
		}
	}
	answer[answer_size++] = i;
	color[i] = BLACK;
}

int main(){
	int i;
	int a,b;
	while(scanf("%d %d", &n, &m) == 2){
		if(n == 0 && m == 0) break;
		for(i=0; i<n; i++){
			color[i] = WHITE;
			adj[i].clear();
		}
		for(i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			adj[a-1].push_back(b-1);
		}
		fail = 0;
		answer_size = 0;
		for(i=0;i<n;i++){
			if(color[i] == WHITE)
				dfs_visit(i);
		}
		if(fail){
			printf("IMPOSSIBLE\n");
		}else{
			for(i=answer_size-1;i>=0;i--)
				printf("%d\n",(answer[i]+1));
		}
	}
}
