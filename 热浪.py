from heapq import *

T, C, start, end = map(int, input().split())
g = [[] for _ in range(T + 1)]
for _ in range(C):
    u, v, w = map(int, input().split())
    g[u].append((v, w))
    g[v].append((u, w))

dist, memo = [0x3f3f3f3f for _ in range(T + 1)], [0 for _ in range(T + 1)]
q = []
dist[start] = 0
heappush(q, (0, start))
while q:
    dis, u = heappop(q)
    memo[u] = 1
    for v, w in g[u]:
        if memo[v]:
            continue
        if dist[v] > dist[u] + w:
            dist[v] = dist[u] + w
            heappush(q, (dist[v], v))
print(dist[end])
