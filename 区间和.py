from collections import defaultdict
from bisect import bisect_left

n, m = map(int, input().split())
points, Add, query = set(), [], []
mp = defaultdict()
for _ in range(n):
    x, c = map(int, input().split())
    points.add(x)
    Add.append((x, c))
for _ in range(m):
    l, r = map(int, input().split())
    query.append((l, r))
    points.add(l)
    points.add(r)
points = sorted(list(points))
pre = [0 for _ in range(len(points) + 2)]
for i, x in enumerate(points, 1):
    mp[x] = i
for x, c in Add:
    pre[mp[x]] += c
for i in range(1, len(points) + 2):
    pre[i] += pre[i - 1]

for l, r in query:
    l, r = bisect_left(points, l), bisect_left(points, r)
    print(pre[r + 1] - pre[l])
