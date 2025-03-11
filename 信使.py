from heapq import *
n, m = map(int, input().split())
g = [[] for _ in range(n + 1)]
for _ in range(m):
    i, j, k = map(int, input().split())
    g[i].append((k, j))
    g[j].append((k, i))

dist, memo = [0x3f3f3f3f for _ in range(n + 1)], [0 for _ in range(n + 1)]
q = []
heappush(q, (0, 1))
dist[1] = 0
while q:
    days, u = heappop(q)
    memo[u] = 1
    for w, v in g[u]:
        if memo[v]:
            continue
        if dist[v] > days + w:
            dist[v] = days + w
            heappush(q, (dist[v], v))
print(-1 if max(dist[1:]) >= 0x3f3f3f3f else max(dist[1:]))
