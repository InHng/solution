from heapq import *
n, p, k = map(int, input().split())
g = [[] for _ in range(n + 1)]
for _ in range(p):
    a, b, l = map(int, input().split())
    g[a].append((l, b))
    g[b].append((l, a))

def check(mid):
    dist, memo = [0x3f3f3f3f for _ in range(n + 1)], [0 for _ in range(n + 1)]
    dist[1] = 0
    q = [(0, 1)]
    while q:
        dis, u = heappop(q)
        if memo[u]:
            continue
        memo[u] = 1
        for l, v in g[u]:
            l = l > mid
            if dist[v] > dis + l:
                dist[v] = dis + l
                heappush(q, (dist[v], v))
    return dist[n] <= k

left, right = -1, 1000001
while left + 1 < right:
    mid = (left + right) >> 1
    if check(mid):
        right = mid
    else:
        left = mid
print(right if right != 1000001 else -1)
