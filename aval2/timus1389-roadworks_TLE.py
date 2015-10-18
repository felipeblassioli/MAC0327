def main():
    from sys import stdin, setrecursionlimit, stdout
    from itertools import islice, izip
    from collections import deque

    setrecursionlimit(10**5+5)
    tkns = iter(stdin.read().split())
    n,m = int(tkns.next()), int(tkns.next()) 

    graph = {str(i): [] for i in xrange(1,n+1)}

    for u,v in izip(tkns, tkns):
        graph[u].append(v)
        graph[v].append(u)

    dp1 = {}
    dp2 = {}
    parent = {}

    visited = set()
    def dfs(v):
        visited.add(v)
        if len(graph[v]) == 0:
            dp1[v] = dp2[v] = 0
            return 

        a = 0
        tmp = deque()
        for c in graph[v]:
            if c not in visited:
                parent[c] = v
                dfs(c)
                a += max(dp1[c],dp2[c])
                tmp.append( 1 + dp2[c] - max(dp1[c],dp2[c]) )

        dp2[v] = a
        if len(tmp) > 0:
            dp1[v] = max( t + a for t in tmp )
        else:
            dp1[v] = 0

    w = stdout.write
    def solve(v):
        a = dp1[v]
        b = dp2[v]
        if b >= a:
            for c in graph[v]:
                if c != parent[v]:
                    solve(c)
        else:
            best = 0
            for c in graph[v]:
                if c != parent[v]:
                    t = dp2[c]
                    x = 1 + t + b - max(t,dp1[c])
                    if x >= best:
                        best = x
                        best_c = c
                    solve(c)
            w('%s %s\n' % (v,best_c))

    root = u
    parent[root] = None
    dfs(root)
    w('%d\n' % max(dp1[root],dp2[root]))
    solve(root)

main()
