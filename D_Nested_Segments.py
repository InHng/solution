import bisect

INF = 0x3f3f3f3f
mod = 10**9 + 7
N = 4 * 10**5 + 1

# 离散化数组
b = []

# 更新树
tree = [0] * N

def lowbit(x):
    return x & -x

def idx(x):
    return bisect.bisect_left(b, x)

def update(i, x):
    while i < N:
        tree[i] += x
        i += lowbit(i)

def query(i):
    ans = 0
    while i > 0:
        ans += tree[i]
        i -= lowbit(i)
    return ans

n = int(input())
a = []
ans = [0 for _ in range(n)]

for i in range(n):
    x, y = map(int, input().split())
    a.append((i, (x, y)))
    b.append(x)
    b.append(y)

a.sort(key=lambda x: x[1][0])
b.sort()
b = list(dict.fromkeys(b))  # 去重

for i in range(n):
    update(idx(a[i][1][1]), 1)

for i in range(n):
    update(idx(a[i][1][1]), -1)
    ans[a[i][0]] = query(idx(a[i][1][1]))

for x in ans:
    print(x)
