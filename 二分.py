from collections import defaultdict

ans, all = 0, 0
n = int(input())
mp = defaultdict(int)
for _ in range(n):
    x, c = map(str, input().split())
    x = int(x)
    if c == ".":
        mp[x] += 1
        mp[x + 1] -= 1
    elif c == "+":
        mp[x] -= 1
        mp[-0x3f3f3f3f3f3f3f3f] += 1
    else:
        mp[x + 1] += 1

for x in sorted(mp.keys()):
    all += mp[x]
    ans = max(ans, all)
print(ans)
