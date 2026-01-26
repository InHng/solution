import sys
input = lambda: sys.stdin.readline().strip()

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
a = [0] + list(map(int, input().split()))
tree = Tree(n + 1)
for i in range(1, n + 1):
    tree.update(i, a[i])
for _ in range(q):
    op = list(map(int, input().split()))
    if op[0] == 1:
        tree.update(op[1], a[op[1] + 1] - a[op[1]])
        tree.update(op[1] + 1, a[op[1]] - a[op[1] + 1])
        a[op[1]], a[op[1] + 1] = a[op[1] + 1], a[op[1]]
    else:
        print(tree.sum(op[1] - 1, op[2]))
