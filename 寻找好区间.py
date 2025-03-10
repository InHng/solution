n, k = map(int, input().split())
ans, right = 0, 1
pre = [0 for _ in range(n + 1)]
s = list(input().split())
for i in range(1, n + 1):
    pre[i] = (s[i - 1] == "byl") + pre[i - 1]
for left in range(1, n + 1):
    while right <= n and pre[right] - pre[left - 1] < k:
        right += 1
    ans += n + 1 - right
print(ans)
