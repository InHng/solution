import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    mp = defaultdict(int)
    for i in range(n):
        mp[a[i]] = max(mp[a[i] + 1], mp[a[i] - 1]) + 1
        ans = max(ans, mp[a[i]])
    print(ans)
