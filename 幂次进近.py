import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

for _ in range(int(input())):
    n, k = map(int, input().split())
    left, right = 0, int((2e18) ** (1.0 / k))
    while left + 1 < right:
        mid = (left + right) // 2
        if n - mid ** k >= 0:
            left = mid
        else:
            right = mid
    print(right if right ** k - n < n - left ** k else left)
