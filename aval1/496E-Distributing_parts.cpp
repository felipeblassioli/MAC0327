#include <cstdio>
#include <set>
#include <algorithm>
#define MAX 100005
#define ACTOR 0
#define PART 1 

using namespace std;

struct Tuple {
	int l,r,type,i;
} everything[2*MAX];

bool cmp(Tuple x, Tuple y) { 
	if (x.l == y.l){
		if(x.type == y.type){
			return x.r < y.r;
		}else{
			//actors come first, i.e actor < type
			return x.type < y.type;
		}
	}
	return x.l < y.l;
}

int n,m;
int main(){
	bool yes;
	int i,k[MAX], assignments[MAX];
	set<pair<int,int> > candidates;
	set<pair<int,int> >::iterator it;

	scanf("%d", &n);
	for(i=0; i<n;i++){
		scanf("%d %d", &everything[i].l, &everything[i].r);
		everything[i].i = i;
		everything[i].type = PART;
	}
	scanf("%d", &m);
	for(i=n; i<n+m; i++){
		scanf("%d %d %d", &everything[i].l, &everything[i].r, &k[i-n]);
		everything[i].i = i-n;
		everything[i].type = ACTOR;
	}
	sort(everything, everything+n+m,cmp);
	
	Tuple *cur;
	yes = true;
	for(i=0; i<n+m; i++){
		cur = &everything[i];
		if(cur->type == ACTOR){
			candidates.insert(make_pair(cur->r, cur->i));
		}else{
			it = candidates.lower_bound(make_pair(cur->r, 0));	
			if((*it).first >= cur->r){
				assignments[cur->i] = (*it).second + 1;	
				if(--k[(*it).second] == 0)
					candidates.erase(*it);
			}else{
				yes = false;
				break;
			}	
		}	
	}	
	if(yes){
		printf("YES\n");
		for(i=0;i<n;i++)
			printf("%d ", assignments[i]);
	}else{
		printf("NO\n");
	}
	return 0;
}
