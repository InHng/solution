import sys
from collections import deque
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

for _ in range(int(input())):
    n = int(input())
    g = [[] for _ in range(n + 1)]
    dist = [-1 for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        g[u].append(v)
        g[v].append(u)
    q = deque()
    for i in range(1, n + 1):
        if len(g[i]) == 1:
            q.append(i)
            dist[i] = 0
    while q:
        u = q.popleft()
        for v in g[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    mx = max(dist[i] for i in range(1, n + 1) if len(g[i]) > 1)
    miku = [i for i in range(1, n + 1) if len(g[i]) > 1 and dist[i] == mx]
    print(len(miku))
    print(*miku)
