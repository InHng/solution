n, H, A = map(int, input().split())
h = list(map(int, input().split()))
a = list(map(int, input().split()))
monsters = [x for x in zip(h, a)]
monsters.sort()

dp = [0 for _ in range(n)]
ans = 0

for i in range(n):
    if H <= monsters[i][0] or A <= monsters[i][1]:
        continue
    dp[i] = 1
    for j in range(i):
        if H <= monsters[j][0] or A <= monsters[j][1]:
            continue
        if monsters[j][0] < monsters[i][0] and monsters[j][1] < monsters[i][1]:
            dp[i] = max(dp[i], dp[j] + 1)
    ans = max(ans, dp[i])
print(ans)
