import sys
from collections import deque, defaultdict
from itertools import chain

MAX = 10005
sys.setrecursionlimit(MAX)
digraph = defaultdict(list) 

all_input = iter(sys.stdin.read().strip().replace('\n', ' ').split(' '))
n = int(all_input.next())
for _ in xrange(n):
    m = int(all_input.next())
    u = all_input.next()
    for i in xrange(m):
        v = all_input.next()
	digraph[u].append(v)

        u = v
	
tour = deque()
def find_tour(u):
    while digraph[u]:
        v = digraph[u].pop()
        find_tour(v)
    tour.appendleft(u)

find_tour('1')
print len(tour)-1, ' '.join(tour)
