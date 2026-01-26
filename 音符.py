from bisect import bisect_right

n, q = map(int, input().split())
b = [0] + list(map(int, input().split()))
t = list(map(int, input().split()))
for i in range(1, len(b)):
    b[i] += b[i - 1]
for ti in t:
    print(bisect_right(b, ti))
