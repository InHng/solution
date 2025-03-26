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
q = [(0, 1)]
dist[1] = 0
while q:
    dis, u = heappop(q)
    for l, v in g[u]:
        if dist[v] > dis + l:
            dist[v] = dis + l
            heappush(q, (dist[v], v))
for _ in range(b):
    p, q = map(int, input().split())
    print(dist[p] + dist[q])
