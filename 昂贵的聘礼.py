from heapq import *

m, n = map(int, input().split())
g = [[] for _ in range(n + 1)]
price, level = [-1], [-1]
for i in range(1, n + 1):
    jiage, dengji, X = map(int, input().split())
    price.append(jiage)
    level.append(dengji)
    for _ in range(X):
        id, value = map(int, input().split())
        g[i].append((id, value))

def dijkstra(down, up):
    dist, memo = [0x3f3f3f3f for _ in range(n + 1)], [0 for _ in range(n + 1)]
    q = []
    heappush(q, (0, 1))
    dist[1] = 0
    while q:
        dis, u = heappop(q)
        if memo[u]:
            continue
        memo[u] = 1
        for v, value in g[u]:
            if dist[v] > dis + value and down <= level[v] <= up:
                dist[v] = dis + value
                heappush(q, (dist[v], v))
    return min((dist[i] + price[i]) for i in range(1, n + 1))

print(min(dijkstra(i, i + m) for i in range(level[1] - m, level[1] + 1)))

