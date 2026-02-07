import sys
from sortedcontainers import SortedList
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n, d = map(int, input().split())
l, ans = 0, 0
a = list(map(int, input().split()))
sl = SortedList()
for i in range(n):
    low, high = a[i] - d + 1, a[i] + d - 1
    idx = sl.bisect_left(low)
    while idx < len(sl) and sl[idx] <= high:
        sl.remove(a[l])
        l += 1
        idx = sl.bisect_left(low)
    sl.add(a[i])
    ans += i - l + 1
print(ans)
