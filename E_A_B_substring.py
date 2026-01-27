import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

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

n = int(input())
s = list(input())
ans, cnt = 0, 0
tree = Tree(2 * n + 10)
tree.update(n + 1, 1)
for c in s:
    if c == 'A':
        cnt += 1
    elif c == 'B':
        cnt -= 1
    tree.update(cnt + n + 1, 1)
    ans += tree.query(cnt + n)
print(ans)
