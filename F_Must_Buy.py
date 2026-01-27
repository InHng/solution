import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n, m = map(int, input().split())
p, v = [0], [0]
dp1, dp2 = [[0 for _ in range(m + 2)] for _ in range(n + 2)], [[0 for _ in range(m + 2)] for _ in range(n + 2)]

for i in range(1, n + 1):
    a, b = map(int, input().split())
    p.append(a)
    v.append(b)
    for j in range(m, -1, -1):
        if j >= p[i]:
            dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - p[i]] + v[i])
        else:
            dp1[i][j] = max(dp1[i][j], dp1[i - 1][j])
    

for i in range(n, 0, -1):
    for j in range(m, -1, -1):
        if j >= p[i]:
            dp2[i][j] = max(dp2[i + 1][j], dp2[i + 1][j - p[i]] + v[i])
        else:
            dp2[i][j] = max(dp2[i][j], dp2[i + 1][j])

maxv, ans = dp1[n][m], []

for i in range(1, n + 1):
    target, w = maxv - v[i], m - p[i]
    
    C = True
    for j in range(w + 1):
        if dp1[i - 1][j] + dp2[i + 1][w-j] >= target:
            C = False
            break
    if C:
        ans.append('C')
    else:
        A = True
        for j in range(m + 1):
            if dp1[i - 1][j] + dp2[i + 1][m-j] == maxv:
                A = False
                break
        ans.append('A' if A else 'B')

print("".join(ans))
