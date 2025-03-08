for _ in range(int(input())):
    n = int(input())
    ans = 0
    g = [[] for _ in range(n + 1)]
    cnt, idx = [0 for _ in range(n + 1)], [0 for _ in range(n + 1)]
    for i in range(1, n):
        u, v = map(int, input().split())
        g[u].append([v, i])
        g[v].append([u, i])

    cnt[1] = 1
    stack = [1]
    while stack:
        u = stack.pop()
        for v, i in g[u]:
            if not cnt[v]:
                cnt[v] = cnt[u] + (i <= idx[u])
                idx[v] = i
                stack.append(v)
    
    print(max(cnt))
