from bisect import bisect_left

n = int(input())
a = [-1000000005] + list(map(int, input().split()))
for _ in range(int(input())):
    x, y = map(int, input().split())
    x = bisect_left(a, x) - 1
    y = (n if bisect_left(a, y + 1) == len(a) else (bisect_left(a, y + 1) - 1))
    print(y - x)
