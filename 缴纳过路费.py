import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

class DSU: # 并查集
    def __init__(self, n):
        self.pre = [i for i in range(n + 1)]
        self.siz = [1 for _ in range(n + 1)]
    
    def find(self, x):
        if self.pre[x] == x:
            return x
        self.pre[x] = self.find(self.pre[x])
        return self.pre[x]
    
    def same(self, x, y):
        return self.find(x) == self.find(y)

    def merge(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return False
        self.siz[x] += self.siz[y]
        self.pre[y] = x
        return True
    
    def size(self, x):
        return self.siz[self.find(x)]

n, m, l, r = map(int, input().split())
dsu1, dsu2 = DSU(n), DSU(n)
for _ in range(m):
    u, v, w = map(int, input().split())
    if w <= r:
        dsu1.merge(u, v)
        if w < l:
            dsu2.merge(u, v)

ans = 0
for i in range(1, n + 1):
    if i == dsu1.find(i):
        ans += dsu1.size(i) * (dsu1.size(i) - 1) // 2
    if i == dsu2.find(i):
        ans -= dsu2.size(i) * (dsu2.size(i) - 1) // 2

print(ans)
