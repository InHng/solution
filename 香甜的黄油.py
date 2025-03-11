from heapq import *

n, p, c = map(int, input().split())
cows = []
for _ in range(n):
    cows.append(int(input()))
g = [[] for _ in range(p + 1)]
for _ in range(c):
    u, v, w = map(int, input().split())
    g[u].append((w, v))
    g[v].append((w, u))

def dijkstra(u):
    dist, memo = [0x3f3f3f3f for _ in range(p + 1)], [0 for _ in range(p + 1)]
    ans = 0
    q = []
    heappush(q, (0, u))
    dist[u] = 0
    while q:
        dis, u = heappop(q)
        memo[u] = 1
        for w, v in g[u]:
            if memo[v]:
                continue
            if dist[v] > dis + w:
                dist[v] = dis + w
                heappush(q, (dist[v], v))
    return sum(dist[cow] for cow in cows)

print(min(dijkstra(i) for i in range(1, p + 1)))
