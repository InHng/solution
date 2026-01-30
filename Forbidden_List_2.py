import sys
from bisect import bisect_left
input = lambda: sys.stdin.readline().strip()

n, q = map(int, input().split())
a = sorted(list(map(int, input().split())))
ans = []

for _ in range(q):
    x, y = map(int, input().split())
    idx = bisect_left(a, x)
    left, right = x, 2000000001
    while left + 1 < right:
        mid = (left + right) >> 1
        idy = bisect_left(a, mid)
        if x + idy - idx + y <= mid:
            right = mid
        else:
            left = mid
    ans.append(str(left))
print("\n".join(ans))
