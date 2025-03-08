dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

for _ in range(int(input())):
    n, m = map(int, input().split())
    ans = 0
    a = [list(map(int, input().split())) for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            if a[i][j]:
                all, a[i][j] = a[i][j], 0
                q = [(i, j)]
                while q:
                    x, y = q.pop()
                    for k in range(4):
                        if 0 <= x + dx[k] < n and 0 <= y + dy[k] < m and a[x + dx[k]][y + dy[k]]:
                            all += a[x + dx[k]][y + dy[k]]
                            a[x + dx[k]][y + dy[k]] = 0
                            q.append((x + dx[k], y + dy[k]))
                ans = max(ans, all)
    print(ans)
