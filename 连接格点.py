import sys
input = lambda: sys.stdin.readline().strip()

class DSU: # 并查集
    def __init__(self, n):
        self.pre = list(range(n + 1))
        self.siz = [1 for _ in range(n + 1)]
    
    def find(self, x):
        x, xcopy = self.pre[x], x
        while x != self.pre[x]:
            x = self.pre[x]
        while xcopy != x:
            self.pre[xcopy], xcopy = x, self.pre[xcopy]
        return x
    
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
    
n, m = map(int, input().split())
ans = 0
dsu = DSU(n * m + 1)
for line in sys.stdin:
    x1, y1, x2, y2 = map(int, line.split())
    u, v = (x1 - 1) * m + y1, (x2 - 1) * m + y2
    dsu.merge(u, v)
for i in range(1, m + 1):
    for j in range(1, n):
        u, v = (j - 1) * m + i, j * m + i
        if dsu.merge(u, v):
            ans += 1

for i in range(1, n + 1):
    for j in range(1, m):
        u, v = (i - 1) * m + j, (i - 1) * m + j + 1
        if dsu.merge(u, v):
            ans += 2
print(ans)
