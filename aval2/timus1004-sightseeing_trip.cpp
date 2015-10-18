#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX_N 105
using namespace std;

const int inf = 10000000;
int graph[MAX_N][MAX_N];
int dis[MAX_N][MAX_N];
int path[MAX_N];
int pre[MAX_N][MAX_N];
int len;

int main()
{
	int tmp;
	int i,j,k;
	int n, m, u, v, w;
	int min_dist;
	while (scanf("%d%d", &n, &m) == 2) {
		len = 0;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j){
				graph[i][j] = inf;
				dis[j][i] = inf; 
				pre[i][j] = i;
			}
		}
		while (m--) {
			scanf("%d%d%d", &u, &v, &w);
			if (w < graph[u][v]) {
				graph[u][v] = w;
				graph[v][u] = w;
				dis[u][v] = w;
				dis[v][u] = w;
			}
		}
		min_dist = inf;
		for(k = 1; k <= n; k++) {
			for(i = 1; i < k; i++)
				for(j = i + 1; j < k; j++)
					if(min_dist > dis[i][j] + graph[j][k] + graph[k][i]) {
						min_dist = dis[i][j] + graph[j][k] + graph[k][i];
						tmp = j; len = 0;
						while (tmp != i) {
							path[len++] = tmp;
							tmp = pre[i][tmp];
						}
						path[len++] = i;
						path[len++] = k;
					}
			for(i = 1; i <= n; ++i)
				for(j = 1; j <= n; ++j)
					if (dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
						pre[i][j] = pre[k][j];
					}
		}

		if (min_dist != inf) {
			printf("%d", path[0]);
			for (i = 1; i < len; ++i)
				printf(" %d", path[i]);
			printf("\n");
		}
		else
			printf("No solution.\n");
	}
	return 0;
}
