import sys

n = input()

digraph = {i: [] for i in xrange(n)}
color = [ -1 for _ in xrange(n) ] 
visited = {i: False for i in xrange(n)}  

for u in xrange(n):
    numbers = map(lambda x: int(x)-1, sys.stdin.next().strip().split(' '))
    numbers.pop()
    for v in numbers:
        digraph[u].append(v)
        digraph[v].append(u)

def has_odd_cycle(u):
    visited[u] = True
    for v in digraph[u]:  
        if not visited[v]:
            color[v] = abs(color[u]-1)
            if has_odd_cycle(v):
                return True
        elif color[v] == color[u]:
            return True
    return False

fail = False
for u in digraph:
    if not visited[u]:
        color[u] = 0
        if has_odd_cycle(u):
            fail = True
            break

if fail: 
    print -1
else:
    print ''.join(map(str,color))
