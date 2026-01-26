import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
g = []
for _ in range(n):
    g.append(int(input()))

dp = [0 for _ in range(n + 1)]

for i in range(n):
    mn = [0 for _ in range(n + 1)]
    mn[n] = dp[n]
    for j in range(n - 1, -1, -1):
        if mn[j + 1] < dp[j]:
            mn[j] = mn[j + 1]
        else:
            mn[j] = dp[j]
            
    all_dots = g[i].count('.')
    black = 0
    white = 0
    dpp = [0 for _ in range(n + 1)]

    for j in range(n + 1):
        cost = black + all_dots - white
        dpp[j] = mn[j] + cost
        
        if j < n:
            if g[i][j] == '#':
                black += 1
            else:
                white += 1
    dp = dpp
print(min(dp))
