import sys
input = sys.stdin.readline

n = int(input())
s, ans, h, v = [], [0 for _ in range(n)], [0 for _ in range(n)], [0 for _ in range(n)]
for i in range(n):
    hi, vi = map(int, input().split())
    h[i], v[i] = hi, vi
    while s and h[s[-1]] < h[i]:
        ans[i] += v[s.pop()]
    if s:
        ans[s[-1]] += v[i]
    s.append(i)
print(max(ans))
