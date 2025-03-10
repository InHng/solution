n = int(input())
ans = 0
a = [0] + list(map(int, input().split()))
s = []
for i in range(1, n + 1):
    while s and a[i] > a[s[-1]]:
        ans ^= s[-1]
        s.pop()
    ans ^= i
    s.append(i)
    print(ans)
