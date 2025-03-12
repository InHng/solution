class Tree:
    def __init__(self, n):
        self.tree = [0] * (n + 10)

    def lowbit(self, x):
        return x & -x

    def update(self, i, x):
        while i < len(self.tree):
            self.tree[i] += x
            i += self.lowbit(i)

    def query(self, i):
        ans = 0
        while i:
            ans += self.tree[i]
            i -= self.lowbit(i)
        return ans

    def sum(self, left, right):
        return self.query(right) - self.query(left)

n, q = map(int, input().split())
zero_idx = -1
last = 1
mx = 0
a = [0] + list(map(int, input().split()))
idx = [[] for _ in range(q + 1)]
tree = Tree(n)

for i in range(1, n + 1):
    idx[a[i]].append(i)
    mx = max(mx, a[i])
    if a[i] == 0:
        a[i] = last
        zero_idx = i
    else:
        last = a[i]

if mx < q:
    if zero_idx != -1:
        a[zero_idx] = q
    else:
        exit(print("NO"))

for i in range(1, q + 1):
    if not idx[i]:
        continue
    if tree.sum(idx[i][0] - 1, idx[i][-1]):  # 有更小的数出现在中间
        exit(print("NO"))
    for i in idx[i]:
        tree.update(i, 1)
print("YES")
print(*a[1:])
