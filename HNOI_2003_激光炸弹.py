n, r = map(int, input().split())
r = min(5001, r)
ans = 0
all = [[0 for _ in range(5005)] for _ in range(5005)]
for _ in range(n):
    x, y, v = map(int, input().split())
    all[x + 1][y + 1] += v
for i in range(1, 5001):
    for j in range(1, 5001):
        all[i][j] += all[i - 1][j] + all[i][j - 1] - all[i - 1][j - 1]
        if i >= r and j >= r:
            ans = max(ans, all[i][j] - all[i - r][j] - all[i][j - r] + all[i - r][j - r])
print(ans)
