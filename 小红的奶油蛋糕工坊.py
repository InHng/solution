n = int(input())
a = list(map(int, input().split()))
b = [(a[i], i) for i in range(n)]
b.sort()
pre = [0] + sorted(a)
c = sorted(a)
for i in range(1, n + 1):
    pre[i] += pre[i - 1]

mn, k = 0x3f3f3f3f, (n + 1) // 2
best = 0
target = 0
mid = k // 2
for i in range(n - k + 1):
    m = i + mid
    num = c[m]
    cnt = (m - i) * num - (pre[m] - pre[i]) + (pre[i + k] - pre[m + 1]) - (i + k - m - 1) * num
    if cnt < mn:
        mn = cnt
        best = i
        target = num

for i in range(best, best + k):
    a[b[i][1]] = target
print(*a)
