from heapq import *

n, m = map(int, input().split())
g = [[] for _ in range(n + 1)]
for _ in range(m):
    x, y, z = map(int, input().split())
    g[x].append((z, y))
    g[y].append((z, x))
A, B = map(int, input().split())

ans = [0.0 for _ in range(n + 1)]
q = []
q.append((-100, -A))
ans[A] = 100
while q:
    dis, u = heappop(q)
    dis, u = -dis, -u
    for w, v in g[u]:
        if ans[v] < ((100 - w) / 100) * dis:
            ans[v] = ((100 - w) / 100) * dis
            q.append((-ans[v], -v))
print(f"{100 / ans[B] * 100:.8f}")
