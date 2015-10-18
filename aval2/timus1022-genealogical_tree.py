from collections import defaultdict, deque
n = input()

graph = {i:  [ int(x) for x in raw_input().strip().split(' ')[:-1] ] for i in xrange(1,n+1)}

GRAY, BLACK = 0,1
def topological(graph):
    order, enter, color = deque(), set(graph), {}
    def dfs(v):
        color[v] = GRAY
        for k in graph.get(v, []):
            c = color.get(k, None)
            if c == GRAY: raise ValuError("cycle")
            if c == BLACK: continue
            enter.discard(k)
            dfs(k)
        order.appendleft(str(v))
        color[v] = BLACK
    while enter:
        dfs(enter.pop())
    return order

print ' '.join(topological(graph))
