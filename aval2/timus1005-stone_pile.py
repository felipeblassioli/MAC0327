import itertools
n = input()
weights = [ int(_) for _ in raw_input().split(' ') ]

N = sum(weights)
best = N
target = best/2
for i in xrange(len(weights)+1):
	for s in itertools.combinations(weights, i):
		x = sum(s)
		if abs(x-target) < abs(best-target):
			best = x

print abs(N - best*2)
