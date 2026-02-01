import sys
from collections import deque
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n = int(input())
g, IN = [[] for _ in range(n + 1)], [0 for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
    IN[u] += 1
    IN[v] += 1
q, p = deque(), [0 for _ in range(n + 1)]
p[1] = 1
vis = [0 for _ in range(n + 1)]
vis[1] = 1
q.append(1)
total_exp = 0
while q:
    u = q.popleft()
    nowp = p[u]
    total_exp = (total_exp + nowp) % mod
    inv_IN = pow(IN[u], mod - 2, mod)
    nextp = nowp * inv_IN % mod
    for v in g[u]:
        if not vis[v]:
            vis[v] = 1
            p[v] = nextp
            q.append(v)
print(total_exp)

