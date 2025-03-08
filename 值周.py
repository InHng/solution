import sys
input = lambda:sys.stdin.readline()

L, M = map(int, input().split())
ans = 0
diff = [0 for _ in range(L + 1)]
for _ in range(M):
    l, r = map(int, input().split())
    diff[l] -= 1
    diff[r + 1] += 1
for i in range(L + 1):
    if i:
        diff[i] += diff[i - 1]
    if not diff[i]:
        ans += 1
print(ans)
