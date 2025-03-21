n = int(input())
a, b = [], []
for _ in range(n):
    A, B = map(int, input().split())
    a.append(A)
    b.append(B)
a.sort()
b.sort()
ans = 0
for i in range(n):
    ans += b[i] - a[i]
    if i and a[i] < b[i - 1]:
        ans -= b[i - 1] - a[i]
print(ans)
