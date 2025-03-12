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
    
n, k = map(int, input().split())
dsu = DSU(n)
edges = []
ans, all = 0, 0
for _ in range(k):
    a = list(map(int, input().split()))
    all += a[2]
    edges.append(a)
edges.sort(key = lambda x: x[2])
for u, v, w in edges:
    if dsu.merge(u, v):
        ans += w
print(all - ans)
