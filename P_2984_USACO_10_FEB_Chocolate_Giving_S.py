import sys
from heapq import *
input = lambda: sys.stdin.readline().strip()

n, m, b = map(int, input().split())
g = [[] for _ in range(n + 1)]
dist = [0x3f3f3f3f for _ in range(n + 1)]
for _ in range(m):
    r, s, l = map(int, input().split())
    g[r].append((l, s))
    g[s].append((l, r))
q = [1]
dist[1] = 0
while q:
    u = heappop(q)
    for l, v in g[u]:
        if dist[v] > dist[u] + l:
            dist[v] = dist[u] + l
            heappush(q, v)
for _ in range(b):
    p, q = map(int, input().split())
    print(dist[p] + dist[q])
