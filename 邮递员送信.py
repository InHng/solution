import sys
input = lambda: sys.stdin.readline().strip()
from heapq import *
mod = 10 ** 9 + 7 # 998244353

n, m = map(int, input().split())
dis_go, dis_back = [0x3f3f3f3f for _ in range(n + 1)], [0x3f3f3f3f for _ in range(n + 1)]
go, back = [[] for _ in range(n + 1)], [[] for _ in range(n + 1)]
dis_go[1] = dis_back[1] = 0
q = []
for _ in range(m):
    u, v, w = map(int, input().split())
    go[u].append((v, w))
    back[v].append((u, w))
heappush(q, (0, 1))
while q:
    _, u = heappop(q)
    for v, w in go[u]:
        if dis_go[u] + w < dis_go[v]:
            dis_go[v] = dis_go[u] + w
            heappush(q, (dis_go[v], v))
heappush(q, (0, 1))
while q:
    _, u = heappop(q)
    for v, w in back[u]:
        if dis_back[u] + w < dis_back[v]:
            dis_back[v] = dis_back[u] + w
            heappush(q, (dis_back[v], v))
print(sum(dis_go[i] + dis_back[i] for i in range(2, n + 1)))
