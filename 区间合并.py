n = int(input())
a = []
for _ in range(n):
    a.append(list(map(int, input().split())))
a.sort()
r, ans = a[0][1], 1
for i in range(1, n):
    if a[i][0] > r:
        ans += 1
    r = max(r, a[i][1])
print(ans)
