#include <bits/stdc++.h>
#define MAX 10005

using namespace std;
int n,m;
int u,v;
vector<int> adj[MAX];
list<int> tour;

void find_tour(int u){
	int v;
	while(!adj[u].empty()){
		v = adj[u].back(); adj[u].pop_back();
		find_tour(v);
	}

	tour.insert(tour.begin(), u);
}

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &m, &u);
		while(m--){
			scanf("%d", &v);
			adj[u].push_back(v);
			u = v;
		}
	}

	find_tour(1);
	printf("%ld ", tour.size()-1);
	for(list<int>::iterator it = tour.begin(); it != tour.end(); it++)
		printf("%d ", *it);
	printf("\n");
	return 0;
}
