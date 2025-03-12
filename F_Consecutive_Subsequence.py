n = int(input())
a = list(map(int, input().split()))

dp = {}
cnt = 0
x = 0

for i in range(n):
    dp[a[i]] = dp.get(a[i] - 1, 0) + 1
    if dp[a[i]] > cnt:
        cnt = dp[a[i]]
        x = a[i]

ans = []
for i in range(n - 1, -1, -1):
    if a[i] == x:
        ans.append(i + 1)
        x -= 1

print(len(ans))
print(" ".join(map(str, ans[::-1])))
