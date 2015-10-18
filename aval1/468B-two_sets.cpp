#include <cstdio>
#include <map>
#include <set>
#include <vector>
#define MAX 100005

int x,a,b;
std::set<int> A,B;
std::set<int>::iterator it;
std::map<int, int> pos;
int label[MAX];
int n;

int main(){
	std::vector<int> q;
	std::vector<int>::iterator qit;

	int yes = 1;
	int i;
	scanf("%d %d %d", &n, &a, &b);
	for(i=0; i<n; i++){
		scanf("%d", &x);
		A.insert(x);
		pos[x] = i;
		label[i] = 0;
	}	
	
	for(it=A.begin(); it!=A.end(); it++){
		x = (*it);
		if(A.find(a-x) == A.end())
			q.push_back(x);
	}
	
	for(qit=q.begin(); qit!=q.end(); qit++){
		x = (*qit);
		B.insert(x);
		A.erase(x);
	}
	
	while(!B.empty()){
		it = B.begin();
		x = (*it);
		if(B.find(b-x) != B.end()){
			label[pos[x]] = 1;
			label[pos[b-x]] = 1;
			B.erase(x);
			if(x != (b-x))
				B.erase(b-x);
		} else if(A.find(b-x) != A.end()){
			label[pos[x]] = 1;
			label[pos[b-x]] = 1;
			B.erase(x);
			A.erase(b-x);
			if( (b-x) != (a-(b-x)) ){	
				A.erase(a-(b-x));
				B.insert(a-(b-x));
			}
		} else{
			yes = 0;
			break;
		}	
	}	

	if(yes){	
		printf("YES\n");	
		for(i=0; i<n; i++)
			printf("%d ", label[i]);
		printf("\n");
	} else {
		printf("NO\n");
	}

	return 0;
}


