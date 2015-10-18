from sys import stdin, stdout
from collections import deque
n,m = map(int, stdin.next().split(' '))

edges = ' '.join([ stdin.next()[:-1] for _ in xrange(m) ]).split(' ')
_edges = [ (edges[i], edges[i+1]) for i in xrange(0,2*m,2) ]
q = int(stdin.next().strip())
indexes = deque(map(int,stdin.next().split(' ')))
forbidden = set(indexes)

parent = {str(i): str(i) for i in xrange(n+1) }
rank = {str(i): 0 for i in xrange(n+1) }

def find(u):
    if parent[u] != u:
        parent[u] = find(parent[u])
    return parent[u]

def union(u,v):
    ru,rv = find(u), find(v)
    if ru != rv:
        if rank[ru] < rank[rv]:
            parent[ru] = rv
        elif rank[ru] > rank[rv]:
            parent[rv] = ru
        else:
            parent[rv] = ru
            rank[ru] += 1
    return ru != rv

count = n
for i, edge in enumerate(_edges):
	if i+1 not in forbidden:
            if union(*edge):
                count -= 1

answers = deque([str(count)], q)
indexes.popleft()
while indexes:
	if union(*_edges[indexes.pop()-1]):
		count -= 1
	answers.appendleft(str(count))
stdout.write(' '.join(answers))
