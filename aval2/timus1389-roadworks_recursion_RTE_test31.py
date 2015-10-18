# RuntimeError at test 31 . I think it's segmentation fault
# python stack frames are heavy. And this solution is recursion intensive
def main():
    from sys import stdin, setrecursionlimit, stdout, exit
    from itertools import islice, izip
    from collections import deque

    setrecursionlimit(10**5+1000)
    tkns = iter(map(int,stdin.read().split()))
    n = tkns.next()
    m = tkns.next()

    graph = [[] for i in xrange(n+1)]

    for u,v in islice(izip(tkns, tkns),m):
        graph[u].append(v)
        graph[v].append(u)

    dp1 = {}
    dp2 = {}
    best = {}
    cache = {}

    def dfs(v):
        if len(graph[v]) == 0:
            dp1[v] = dp2[v] = 0
            best[v] = -1
            cache[v] = 0
            return 

        a = 0
        for c in graph[v]:
            graph[c].remove(v)
            dfs(c)
            a += cache[c]

        dp2[v] = a
        M = 0
        for c in graph[v]:
            b = 1 + dp2[c] + a - cache[c] 
            if M <= b:
                M = b
                best_c = c

        dp1[v] = M
        if dp2[v] >= dp1[v]:
            cache[v] = dp2[v]
            best[v] = -1
        else:
            cache[v] = dp1[v]
            best[v] = best_c

    w = stdout.write
    ret = []
    app = ret.append
    def solve(v):
        for c in graph[v]:
            solve(c)
        if best[v] != -1:
            app('%s %s\n' % (v,best[v]))

    from random import randint
    root = randint(1,n)
    dfs(root)
    w('%d\n' % max(dp1[root],dp2[root]))
    solve(root)
    w(''.join(ret))

main()
