n, q = map(int, input().split())
a = list(map(int, input().split()))
diff, cnt = [0 for _ in range(n + 2)], []
for _ in range(q):
    l, r = map(int, input().split())
    diff[l] += 1
    diff[r + 1] -= 1
for i in range(1, n + 1):
    diff[i] += diff[i - 1]
    cnt.append(diff[i])
a.sort(reverse = True)
cnt.sort(reverse = True)
print(sum(cnt[i] * a[i] for i in range(n)))
