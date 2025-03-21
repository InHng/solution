from collections import defaultdict

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

def find(x):
    left, right = -1, len(points)
    while left + 1 < right:
        mid = (left + right) >> 1
        if points[mid] > x:
            right = mid
        else:
            left = mid
    return left + 1

for l, r in query:
    l, r = find(l), find(r)
    print(pre[r] - pre[l - 1])
