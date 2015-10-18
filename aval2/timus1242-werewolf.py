import sys
from collections import namedtuple, defaultdict

Node = namedtuple('Node', ['children','parents'])

n = input()
graph = defaultdict(lambda: Node([],[]))

for line in sys.stdin:
    line = line.strip()
    if line == 'BLOOD':
        break

    c,p = line.split(' ')
    graph[c].parents.append(p)
    graph[p].children.append(c)

victims = [ line.strip() for line in sys.stdin ]

marked = set()
for v in victims:
    marked.add(v)
    q = [ x for x in graph[v].parents ]
    while q:
        u = q.pop()
        marked.add(u)
        q.extend(graph[u].parents)
    
    q = [ x for x in graph[v].children ]
    while q:
        u = q.pop()
        marked.add(u)
        q.extend(graph[u].children)

victims = [ str(i) for i in xrange(1,n+1) if str(i) not in marked ]
if len(victims) > 0:
    print ' '.join(victims)
else:
    print '0'
