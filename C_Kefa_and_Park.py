n, m = map(int, input().split())
a = [-1] + list(map(int, input().split()))
g = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    x, y = map(int, input().split())
    g[x].append(y)
    g[y].append(x)

ans = 0
stack = [[1, -1, a[1]]]
while stack:
    u, father, cnt = stack.pop()
    if u ^ 1 and len(g[u]) == 1:
        ans += 1
    for v in g[u]:
        if v == father or cnt + a[v] > m:
            continue
        if a[v]:
            stack.append([v, u, cnt + 1])
        else:
            stack.append([v, u, 0])

print(ans)
