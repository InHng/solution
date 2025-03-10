n = int(input())
ans, h = [0 for _ in range(n)], []
for _ in range(n):
    h.append(int(input()))
s = []
for i in range(n - 1, -1, -1):
    while s and s[-1][0] <= h[i]:
        s.pop()
    if s:
        ans[i] = s[-1][1]
    s.append([h[i], i + 1])
for x in ans:
    print(x)
