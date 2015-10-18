import sys

def main():
    def dfs(graph, visited, u):
        visited.add(u)
        for v in graph[u]:
            if v not in visited:
                dfs(graph, visited, v)
    stdin = sys.stdin
    visited = set()
    m,n = map(int, stdin.next().split())
    graph = {str(i): set() for i in xrange(1,m+1)}

    wrongs = 0
    for box in xrange(1, m+1):
        u = str(box)
        adj = graph[u]
        for v in stdin.next().split():
            if v != u:
                wrongs += 1
                adj.add(v)
                graph[v].add(u)

    components_counts = 0
    for v in graph:
        if v not in visited and len(graph[v]) > 0:
            dfs(graph, visited, v)
            components_counts += 1

    print wrongs + max(components_counts-1, 0)

main()
