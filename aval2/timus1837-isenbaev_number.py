n = input()
from collections import defaultdict, deque
import itertools

levels = defaultdict(lambda: -1)
def bfs(graph, start):
	queue = deque([start])

	if start in graph:
		levels[start] = 0
		while queue:
			vertex = queue.popleft()
			for c in graph[vertex]:
				if levels[c] == -1:
					levels[c] = levels[vertex] + 1 
					queue.append(c)
			
graph = defaultdict(set)
for _ in xrange(n):
	for k,v in itertools.permutations(raw_input().strip().split(' '), 2):
		graph[k].add(v)
	
bfs(graph, 'Isenbaev')
for name in sorted([k for k in graph.keys() ]):
	print name, levels[name] if levels[name] >= 0 else "undefined"


