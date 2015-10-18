def main():
    from sys import stdin, stdout
    from itertools import izip
    from collections import deque

    tkns = iter(map(int,stdin.read().split()))
    n = tkns.next()
    m = tkns.next()

    graph = [[] for i in xrange(n+1)]

    for u,v in izip(tkns, tkns):
        graph[u].append(v)
        graph[v].append(u)

    dp1 = {}
    dp2 = {}
    best = {}
    cache = {}

    root = u
    reverse_topological_order = deque(maxlen=n)
    stk = deque([root],n)
    app = stk.append
    while stk:
        v = stk.pop()
        if len(graph[v]) == 0:
            dp1[v] = dp2[v] = 0
            best[v] = -1
            cache[v] = 0
        else:
            reverse_topological_order.appendleft(v)
            for c in graph[v]:
                graph[c].remove(v)
                app(c)

    for v in reverse_topological_order:
        dp2[v] = sum( cache[c] for c in graph[v] )
        a = dp2[v]
        M = 0
        for c in graph[v]:
            b = 1 + dp2[c] + a - cache[c] 
            if M <= b:
                M = b
                best_c = c

        dp1[v] = M
        if dp2[v] >= dp1[v]:
            best[v] = -1
            cache[v] = dp2[v]
        else:
            best[v] = best_c
            cache[v] = dp1[v]

    w = stdout.write
    stk = deque([root],n)
    w('%d\n' % cache[root])
    ret = []
    app = ret.append
    while stk:
        v = stk.pop()
        if best[v] != -1:
            app('%s %s\n' % (v,best[v]))
        stk.extend(graph[v])
    w(''.join(ret))

main()
