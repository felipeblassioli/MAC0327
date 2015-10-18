def hopcroft_karp(adj, U, V, INF=99999, write=None):
    from collections import deque

    def BFS(adj, dist, pair_u, pair_v):
        Q = deque()
        for u in U:
            if pair_u[u] == -1:
                dist[u] = 0
                Q.append(u)
            else:
                dist[u] = INF
        dist[-1] = INF
        while Q:
            u = Q.popleft()
            if dist[u] < dist[-1]:
                for v in adj[u]:
                    if dist[ pair_v[v] ] == INF:
                        dist[ pair_v[v] ] = dist[u] + 1
                        Q.append(pair_v[v])
        return dist[-1] != INF

    def DFS(dist, pair_u, pair_v, u):
        if u != -1:
            for v in adj[u]:
                if dist[ pair_v[v] ] == dist[u] + 1:
                    if DFS(dist, pair_u, pair_v, pair_v[v]):
                        pair_v[v] = u
                        pair_u[u] = v
                        return True
            dist[u] = INF
            return False
        return True

    pair_u = {u: -1 for u in U}
    pair_v = {v: -1 for v in V}
    dist = {}
    matching = 0
    while BFS(adj, dist, pair_u, pair_v):
        for u in U:
            if pair_u[u] == -1:
                if DFS(dist, pair_u, pair_v, u):
                    matching += 1

    write('%d\n' % matching)
    for k,v in pair_u.items():
        if v != -1:
            write(k+' '+v+'\n')

def main():
    from sys import stdin, stdout
    from itertools import islice, izip
    tkns = iter(stdin.read().split())
    n,m = int(tkns.next()), int(tkns.next())
    graph = {str(i): [] for i in xrange(1,n+1)}
    for u,v in islice(izip(tkns,tkns),m):
        graph[u].append(v)
        graph[v].append(u)
    
    def dfs(adj, visited, color, u):
        visited.add(u)
        for v in adj[u]:
            if v not in visited:
                color[v] = not color[u]
                partitions[color[v]].add(v)
                dfs(graph, visited, color, v)

    visited = set()
    color = {}
    partitions = {True: set(), False: set()}
    for u in graph:
        if u not in visited:
            color[u] = True
            partitions[True].add(u)
            dfs(graph, visited, color, u)

    matchings = hopcroft_karp(graph, partitions[True], partitions[False], INF=999999, write=stdout.write)

main()
