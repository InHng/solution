import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
mx = -1
ans = ["a"] * 2000000
for _ in range(n):
    s, _, *a = input().split()
    a = [*map(int, a)]
    j = 0
    for x in a:
        x -= 1
        for j in range(max(j, x), x + len(s)):
            ans[j] = s[j - x]
    mx = max(mx, j)
print(''.join(ans[:mx + 1]))
