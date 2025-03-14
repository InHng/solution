L, M = map(int, input().split())
diff = [0 for _ in range(L + 2)]
for _ in range(M):
    l, r = map(int, input().split())
    diff[l] += 1
    diff[r + 1] -= 1
ans = (diff[0] == 0)
for i in range(1, L + 1):
    diff[i] += diff[i - 1]
    ans += (diff[i] == 0)
print(ans)
