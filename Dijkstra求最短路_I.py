from heapq import *

n, m = map(int, input().split())
g = [[] for _ in range(n + 1)]
for _ in range(m):
    x, y, z = map(int, input().split())
    g[x].append((z, y))

dist, memo = [0x3f3f3f3f for _ in range(n + 1)], [0 for _ in range(n + 1)]
dist[1] = 0
q = []
heappush(q, (0, 1))
while q:
    dis, u = heappop(q)
    if memo[u]:
        continue
    memo[u] = 1
    for l, v in g[u]:
        if dist[v] > dis + l:
            dist[v] = dis + l
            heappush(q, (dist[v], v))
print(-1 if dist[n] >= 0x3f3f3f3f else dist[n])
