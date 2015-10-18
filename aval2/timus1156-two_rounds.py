from functools import wraps
def memo(func):
	cache = {}
	@wraps(func)
	def wrap(*args):
		if args not in cache:
			cache[args] = func(*args)
		return cache[args]
	return wrap

def main():
	from sys import stdin
	from itertools import izip, islice
	from collections import namedtuple

	tokens = iter(stdin.read().strip().split())
	n,m = int(tokens.next()), int(tokens.next())

	graph, visited, color = {str(u): set() for u in xrange(1,2*n+1)}, set(), {}
	for u,v in islice(izip(tokens,tokens), m):
		graph[u].add(v)
		graph[v].add(u)

	def has_odd_cycle(graph, visited, color, bipartition, u):
		visited.add(u)
		new_color = abs(color[u]-1)
		for v in graph[u]:
			if v not in visited:
				color[v] = new_color
				bipartition[new_color].add(v)
				if has_odd_cycle(graph, visited, color, bipartition, v):
					return True
			elif color[v] == color[u]:
				return True
		return False

	fail, count, bipartitions = False, 0, {}
	for u in graph:
		if u not in visited:
			bipartitions[count] = [set(),set()]

			color[u] = 0
			bipartitions[count][0].add(u)
			if has_odd_cycle(graph, visited, color, bipartitions[count], u):
				fail = True
				break
			count += 1
	
	if fail:
		print "IMPOSSIBLE"
	else:
		@memo
		def dp(i,l,r,mode):
			if l > n or r > n: return ''
			elif i == count and l == n and r == n: return str(mode)
			a,b = len(bipartitions[i][0]), len(bipartitions[i][1])
			if len(dp(i+1, l+a, r+b,0)) > 0:
				return str(mode)+dp(i+1,l+a, r+b,0)
			elif len(dp(i+1, l+b, r+a,0)) > 0:
				return str(mode)+dp(i+1,l+b,r+a,1)
			else:
				return ''
		
		mapping = dp(0,0,0,'')
		if mapping:
			A = set()
			B = set() 
			for i,c in enumerate(mapping):
				bp = bipartitions[i]
				if c == '0':
					A = A.union(bp[0])
					B = B.union(bp[1])
				else:
					A = A.union(bp[1])
					B = B.union(bp[0])
			print ' '.join(A)
			print ' '.join(B)
		else:
			print "IMPOSSIBLE"


		# print len(bigger), len(smaller)

main()
