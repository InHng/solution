from collections import deque
for _ in range(int(input())):
    n, st, en = map(int, input().split())
    g = [[] for _ in range(n + 1)]
    for __ in range(n - 1):
        u, v = map(int, input().split())
        g[u].append(v)
        g[v].append(u)
    q = deque()
    ans = [str(en)]
    q.append((en, -1))
    while q:
        u, father = q.popleft()
        for v in g[u]:
            if v == father:
                continue
            q.append((v, u))
            ans.append(str(v))
    print(" ".join(ans[::-1]))
